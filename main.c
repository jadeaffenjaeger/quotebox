#include "stm8s.h"
#include "dfplayer.h"
#include "clock.h"
#include "awu.h"

void main() {
    // Configure LED pin
    gpio_B->DDR = (1 << P5);
    gpio_B->CR1 = (1 << P5);

    clock_init();
    dfplayer_init();
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
        gpio_B->ODR ^= (1 << P5);
    }
}
