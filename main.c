#include "stm8s.h"
#include "uart.h"
#include "clock.h"

void main() {
	// Configure pins
    gpio_B->DDR = (1 << P5);
    gpio_B->CR1 = (1 << P5);

    clock_init();
    uart_init();

	for(;;) {
        uint8_t data = uart_receive();
        gpio_B->ODR ^= (1 << P5);
        uart_send(data);
		/* for(uint32_t i = 0; i < 1600000; i++) nop();*/
	}
}
