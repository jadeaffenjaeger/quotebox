#ifndef _STM8S_H_
#define _STM8S_H_

#include <stdint.h>

/*
 *GPIO
 */

struct gpio_t {
    uint8_t ODR;
    uint8_t IDR;
    uint8_t DDR;
    uint8_t CR1;
    uint8_t CR2;
};

#define GPIOA_BASE 0x5000
#define GPIOB_BASE 0x5005
#define GPIOC_BASE 0x500A
#define GPIOD_BASE 0x500F
#define GPIOE_BASE 0x5014
#define GPIOF_BASE 0x5019

#define P0 0
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7

static volatile struct gpio_t * gpio_A = (struct gpio_t *) GPIOA_BASE;
static volatile struct gpio_t * gpio_B = (struct gpio_t *) GPIOB_BASE;
static volatile struct gpio_t * gpio_C = (struct gpio_t *) GPIOC_BASE;
static volatile struct gpio_t * gpio_D = (struct gpio_t *) GPIOD_BASE;
static volatile struct gpio_t * gpio_E = (struct gpio_t *) GPIOE_BASE;
static volatile struct gpio_t * gpio_F = (struct gpio_t *) GPIOF_BASE;

/*
 *CLK
 */

struct clk_t {
    uint8_t ICKR;
    uint8_t ECKR;
    uint8_t reserved0;
    uint8_t CMSR;
    uint8_t SWR;
    uint8_t SWCR;
    uint8_t CKDIVR;
    uint8_t PCKENR1;
    uint8_t CSSR;
    uint8_t PCKENR2;
    uint8_t HSITRIMR;
    uint8_t SWIMCCR;
};

#define CLK_BASE 0x50C0

#define CLK_PCKENR1_PCKEN13 (1 << 3)
#define CLK_PCKENR2_PCKEN22 (1 << 2)

/*
 *AWU
 */

struct awu_t {
    uint8_t CSR1;
    uint8_t APR;
    uint8_t TBR;
};

#define AWU_BASE 0x50F0

/*
 *UART
 */

struct uart_t {
    uint8_t SR;
    uint8_t DR;
    uint8_t BRR1;
    uint8_t BRR2;
    uint8_t CR1;
    uint8_t CR2;
    uint8_t CR3;
    uint8_t CR4;
    uint8_t CR5;
    uint8_t GTR;
    uint8_t PSCR;
};

#define UART_SR_TXE     (1 << 7)
#define UART_SR_TC      (1 << 6) 
#define UART_SR_RXNE    (1 << 5) 

#define UART_CR1_M      (1 << 4)

#define UART_CR2_TEN    (1 << 3)
#define UART_CR2_REN    (1 << 2)

#define UART1_BASE 0x5230

/*
 *ADC
 */

struct adc_t {
    uint8_t DBR;
    uint8_t reserved[12];
    uint8_t CSR;
    uint8_t CR1;
    uint8_t CR2;
    uint8_t CR3;
    uint8_t DRH;
    uint8_t DRL;
    uint8_t TDRH;
    uint8_t TDRL;
    uint8_t HTRH;
    uint8_t HTRL;
    uint8_t LTRH;
    uint8_t LTRL;
    uint8_t AWSRH;
    uint8_t AWSRL;
    uint8_t AWCRH;
    uint8_t AWCRL;
};

#define ADC1_BASE 0x53E0

/*
 *ASM instructions
 */

#define     nop()       __asm__("nop\n")
#define     halt()      __asm__("halt\n")
#define     rim()       __asm__("rim\n")
#define     wfi()       __asm__("wfi\n")

#endif // _STM8S_H_
