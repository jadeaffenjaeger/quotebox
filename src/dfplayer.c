#include "dfplayer.h"

static dfplayer_t dfplayer = {
    .start = 0x7E,
    .version = 0xFF,
    .length = 6,
    .end = 0xEF
};

static dfplayer_t dfplayer_response = {
    .start = 0x7E,
    .version = 0xFF,
    .length = 6,
    .end = 0xEF
};

static uint16_t _get_u16(uint8_t * ptr) {
    return (uint16_t) (ptr[0] << 8 | ptr[1]);
}

static void _set_u16(uint8_t * ptr, uint16_t val) {
    ptr[0] = (uint8_t) val >> 8;
    ptr[1] = (uint8_t) val;
}

static void _update_checksum() {

    uint16_t acc = 0;

    acc += dfplayer.version;
    acc += dfplayer.length;
    acc += dfplayer.command;
    acc += dfplayer.feedback;
    acc += dfplayer.param_H;
    acc += dfplayer.param_L;

    acc = -acc;

    _set_u16(&dfplayer.checksum_H, acc);
}

void _send_command(dfplayer_cmd_t command, uint16_t param) {

    dfplayer.command = (uint8_t) command;
    /* dfplayer.param_H = param >> 8;*/
    /* dfplayer.param_L = param > 8;*/
    /* _set_u16(&dfplayer.param_H, param);*/
    _update_checksum();

    uart_send_buf((const uint8_t *) dfplayer, sizeof(dfplayer_t));
}

bool _get_response() {

    /* Wait for start*/
    while(uart_receive() != 0x7E);

    if(uart_receive() != dfplayer_response.version) return false;
    if(uart_receive() != dfplayer_response.length) return false;

    dfplayer_response.command = uart_receive();
    dfplayer_response.feedback = uart_receive();
    dfplayer_response.param_H = uart_receive();
    dfplayer_response.param_L = uart_receive();
    dfplayer_response.checksum_H = uart_receive();
    dfplayer_response.checksum_L = uart_receive();

    if(uart_receive() != dfplayer_response.end) return false;

    //TODO: Check checksum
    return true;
}

void dfplayer_init() {
    uart_init();
}

uint16_t dfplayer_get_tracks() {
    _send_command(0x47, 0);
    _get_response();
    return _get_u16(&dfplayer_response.param_H);
}

void dfplayer_set_volume(uint8_t volume) {
    if (volume > 30) {
        volume = 30;
    }
    _send_command(CMD_SET_VOL, volume);
}

void dfplayer_standby() {
    _send_command(CMD_STDBY, 0);
}

void dfplayer_wakeup() {
    _send_command(CMD_NORMAL, 0);
}

void dfplayer_play() {
    _send_command(CMD_PLAY, 0);
}

void dfplayer_reset() {
    _send_command(CMD_RESET, 0);
}

void dfplayer_set_track(uint16_t num) {
    _send_command(CMD_NUM, num);
}

void dfplayer_playback_mode(dfplayer_mode_t mode) {
    _send_command(CMD_PLAYBACK_MODE, (uint16_t) mode);
}

void dfplayer_set_SD() {
    _send_command(CMD_PLAYBACK_SRC, 1);
}

