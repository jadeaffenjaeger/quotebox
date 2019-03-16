#ifndef _UART_H_
#define _UART_H_

#include "stm8s.h"

void uart_init();
void uart_send(uint8_t data);
void uart_send_buf(const uint8_t * data, uint8_t len);
uint8_t uart_receive();

#endif // _UART_H_
