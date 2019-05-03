#include "stm8s.h"

#include "clock.h"
#include "uart.h"
#include "awu.h"
#include "gpio.h"

#include "dfplayer.h"

#define VOLUME 28
#define ARR_LEN(x) sizeof(x)/sizeof(x[0])

void start_player();
void stop_player();

void main() {

    /* Array of variable idle times between 5 and 10 minutes (in seconds)*/
    uint16_t sleep_times[] = { 557, 547, 332, 581, 591,
                               459, 507, 417, 565, 598,
                               373, 351, 395, 365, 490,
                               466, 539, 536, 442, 472,
                               472, 470, 511, 416, 512 };
    uint8_t sleep_idx = 0;
    uint8_t track_idx = 1;

    /* Bring up hardware peripherals*/
    clock_init();
    uart_init();
    dfplayer_init();
    gpio_init();

    /* Get number of tracks on SD card to loop through*/
    start_player();
    uint16_t tracks = dfplayer_get_tracks();

    for(;;) {
        /* Bring up player*/
        gpio_led_on();
        start_player();

        /* Play next track*/
        dfplayer_set_track(track_idx++);
        if (track_idx > tracks) {
            track_idx = 1;
        }

        /* wait for Player to finish*/
        do {
            awu_sleep(MSECONDS_100);
        } while(gpio_player_busy() == true);

        /* shut down player*/
        stop_player();
        gpio_led_off();

        /* Go to sleep for next interval*/
        awu_sleep_n_seconds(sleep_times[sleep_idx]);
        sleep_idx++;
        if (sleep_idx >= ARR_LEN(sleep_times)) {
            sleep_idx = 0;
        }
    }
}

/* Do the necessary steps for the DFPlayer to be ready*/
void start_player() {
    gpio_fet_on();
    dfplayer_reset();
    dfplayer_wait_for_init();
    dfplayer_set_volume(VOLUME);
}

/* Shut down DFPlayer*/
void stop_player() {
    gpio_fet_off();
}
