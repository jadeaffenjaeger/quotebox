#include "stm8s.h"
#include "dfplayer.h"
#include "clock.h"
#include "awu.h"
#include "gpio.h"


void start_player();
void stop_player();

void main() {

    /* Bring up hardware peripherals*/
    clock_init();
    dfplayer_init();
    gpio_init();

    for(;;) {
        gpio_led_on();
        start_player();
        dfplayer_set_track(1);
        awu_sleep(SECONDS_10);
        stop_player();
        gpio_led_off();
        awu_sleep(SECONDS_10);
    }
}

/* Do the necessary steps for the DFPlayer to be ready*/
void start_player() {
    gpio_fet_on();
    dfplayer_reset();
    dfplayer_wait_for_init();
    dfplayer_set_volume(30);
}

/* Shut down DFPlayer*/
void stop_player() {
    gpio_fet_off();
}
