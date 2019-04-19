#include "stm8s.h"
#include "dfplayer.h"
#include "clock.h"
#include "awu.h"
#include "gpio.h"


void main() {
    clock_init();
    dfplayer_init();
    gpio_led_init();

    dfplayer_reset();

    awu_sleep(MSECONDS_100);
    uint16_t test = dfplayer_get_tracks();
    dfplayer_set_volume(20);
    dfplayer_set_track(1);

    for(;;) {
        awu_sleep(SECONDS_1);
        gpio_led_toggle();
    }
}
