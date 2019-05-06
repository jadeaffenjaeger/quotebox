#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm8s.h"
#include <stdbool.h>

void gpio_init();
void gpio_led_on();
void gpio_led_off();
void gpio_led_toggle();

void gpio_fet_on();
void gpio_fet_off();
void gpio_fet_toggle();

bool gpio_player_busy();

#endif // _GPIO_H_
