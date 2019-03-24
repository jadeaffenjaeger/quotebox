#include "awu.h"

static volatile struct awu_t * const awu = (struct awu_t *) AWU_BASE;

void awu_sleep() {
    awu->TBR = 0b1100;
    awu->APR = 35;
    awu->CSR1 = (1 << 4);

    halt();
}

void isr_awu(void) __interrupt(1) {
    /* Read AWU CSR to clear Interrupt*/
    volatile uint8_t dummy = awu->CSR1;
}
