#ifndef LFSR_H_
#define LFSR_H_

#include <stdint.h>

/*
 *Defines polynomial and current state of the LFSR
 */
typedef struct lfsr {
    const uint8_t mask;
    uint8_t state;
} lfsr_t;

/*
 *Get pseudo-random 8 Bit sequence
 */
uint8_t lfsr_get_byte(lfsr_t* reg);

#endif
