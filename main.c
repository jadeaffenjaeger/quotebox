#include "stm8s.h"
#include "dfplayer.h"
#include "clock.h"
#include "awu.h"

void main() {
    // Configure LED pin
    gpio_B->DDR = (1 << P5);
    gpio_B->CR1 = (1 << P5);

    clock_init();

    for(;;) {
        awu_sleep(SECONDS_5);
        gpio_B->ODR ^= (1 << P5);
    }
}
