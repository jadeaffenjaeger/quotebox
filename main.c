#include "stm8s.h"
#include "dfplayer.h"
#include "clock.h"
#include "awu.h"
#include "gpio.h"


void main() {
    // Configure LED pin

    clock_init();
    dfplayer_init();
    gpio_led_init();

    awu_sleep(MSECONDS_100);
    dfplayer_reset();
    awu_sleep(MSECONDS_100);
    dfplayer_set_volume(15);
    awu_sleep(MSECONDS_100);
    dfplayer_set_track(0);
    awu_sleep(MSECONDS_100);
    dfplayer_play();
    awu_sleep(MSECONDS_100);

    for(;;) {
        volatile uint16_t test = dfplayer_get_tracks();
        awu_sleep(SECONDS_1);
        gpio_led_toggle();
    }
}
