#include "gpio.h"

static volatile struct gpio_t * gpio_A = (struct gpio_t *) GPIOA_BASE;
static volatile struct gpio_t * gpio_B = (struct gpio_t *) GPIOB_BASE;
static volatile struct gpio_t * gpio_C = (struct gpio_t *) GPIOC_BASE;
static volatile struct gpio_t * gpio_D = (struct gpio_t *) GPIOD_BASE;
static volatile struct gpio_t * gpio_E = (struct gpio_t *) GPIOE_BASE;
static volatile struct gpio_t * gpio_F = (struct gpio_t *) GPIOF_BASE;


void gpio_led_init() {
    gpio_B->DDR = (1 << P5);
    gpio_B->CR1 = (1 << P5);
}

void gpio_led_on() {
    gpio_B->ODR |= (1 << P5);
}

void gpio_led_off() {
    gpio_B->ODR &= ~(1 << P5);
}

void gpio_led_toggle() {
    gpio_B->ODR ^= (1 << P5);
}
