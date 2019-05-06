#ifndef _DFPLAYER_H_
#define _DFPLAYER_H_

#include "uart.h"
#include <stdbool.h>

typedef enum dfplayer_cmd {
    CMD_NXT                 = 0x01,
    CMD_PRV                 = 0x02,
    CMD_NUM                 = 0x03,
    CMD_INC_VOL             = 0x04,
    CMD_DEC_VOL             = 0x05,
    CMD_SET_VOL             = 0x06,
    CMD_SET_EQ              = 0x07,
    CMD_PLAYBACK_MODE       = 0x08,
    CMD_PLAYBACK_SRC        = 0x09,
    CMD_STDBY               = 0x0A,
    CMD_NORMAL              = 0x0B,
    CMD_RESET               = 0x0C,
    CMD_PLAY                = 0x0D,
    CMD_PAUSE               = 0x0E,
    CMD_FOLDER              = 0x0F,
    CMD_VOL_ADJ             = 0x10,
    CMD_REPEAT              = 0x11
} dfplayer_cmd_t;

typedef enum dfplayer_mode {
    REPEAT                  = 0,
    FOLDER_REPAT            = 1,
    SINGLE_REPAT            = 2,
    RANDOM                  = 3,
} dfplayer_mode_t;

typedef struct dfplayer {
    const uint8_t start;
    const uint8_t version;
    uint8_t length;
    uint8_t command;
    uint8_t feedback;
    uint8_t param_H;
    uint8_t param_L;
    uint8_t checksum_H;
    uint8_t checksum_L;
    const uint8_t end;
} dfplayer_t;

void dfplayer_init();

uint16_t dfplayer_get_tracks();
void dfplayer_set_volume(uint8_t volume);
void dfplayer_standby();
void dfplayer_wakeup();
void dfplayer_reset();
void dfplayer_set_track(uint16_t num);
void dfplayer_set_SD();
void dfplayer_play();
void dfplayer_playback_mode(dfplayer_mode_t mode);
bool dfplayer_wait_for_init();


#endif // _DFPLAYER_H_
