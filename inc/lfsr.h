#ifndef __LFSR_H
#define __LFSR_H


/*
 *Defines polynomial and current state of the LFSR
 */
typedef struct lfsr {
    uint8_t mask;
    uint8_t state;
} lfsr_t;

/*
 *Get pseudo-random 8 Bit sequence
 */
uint8_t lfsr_get_byte(lfsr_t* reg);

#endif
