#include "dfplayer.h"

static volatile dfplayer_t dfplayer_request = {
    .start = 0x7E,
    .version = 0xFF,
    .length = 6,
    .end = 0xEF
};

static volatile dfplayer_t dfplayer_response = {
    .start = 0x7E,
    .version = 0xFF,
    .length = 6,
    .end = 0xEF
};

static void _update_checksum() {

    volatile int16_t acc = 0;

    acc += dfplayer_request.version;
    acc += dfplayer_request.length;
    acc += dfplayer_request.command;
    acc += dfplayer_request.feedback;
    acc += dfplayer_request.param_H;
    acc += dfplayer_request.param_L;

    acc = -acc;

    dfplayer_request.checksum_H = acc >> 8;
    dfplayer_request.checksum_L = acc;
}

void _send_command(dfplayer_cmd_t command, uint16_t param) {

    dfplayer_request.command = (uint8_t) command;
    dfplayer_request.param_H = (param >> 8);
    dfplayer_request.param_L = param;
    _update_checksum();

    uart_send_buf((const uint8_t *) dfplayer_request, sizeof(dfplayer_t));
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
    _send_command(0x48, 0);
    _get_response();
    return (dfplayer_response.param_H << 8 | dfplayer_response.param_L);
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
    _send_command(CMD_PLAYBACK_SRC, 0);
}

bool dfplayer_wait_for_init() {
    bool response = _get_response();

    if(response == false) {
        return false;
    }

    // Response is error message
    if(dfplayer_response.command == 0x40) {
        return false;
    }

    return true;
}

