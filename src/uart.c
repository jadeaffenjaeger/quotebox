#include "stm8s.h"

static volatile struct uart_t * const uart1 = (struct uart_t *) UART1_BASE;

void uart_init() {
    /* Set transmission to 8N1*/
    uart1->CR1 &= ~UART_CR1_M;

    /* Set to 9600 Baud at 16MHz*/
    uart1->BRR2 = 0x03;
    uart1->BRR1 = 0x68;

    uart1->CR2 |= UART_CR2_TEN;
    uart1->CR2 |= UART_CR2_REN;
}

void uart_send(uint8_t data) {
    uart1->DR = data;
    while((uart1->SR & UART_SR_TC) == 0);
}

void uart_send_buf(const uint8_t * data, uint8_t len) {
    for(uint8_t i = 0; i < len; i++) {
        uart_send(data[i]);
    }
}

uint8_t uart_receive() {
    while((uart1->SR & UART_SR_RXNE) == 0);
    return uart1->DR;
}
