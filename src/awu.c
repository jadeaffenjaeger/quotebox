#include "awu.h"

static volatile struct awu_t * const awu = (struct awu_t *) AWU_BASE;

static void _set_interval(awu_interval_t interval) {

    uint8_t tbr = 0b1100;
    uint8_t apr = 42;

    /* Get register values*/
    switch(interval) {
        case MSECONDS_100:
            tbr = 0b1001;
            apr = 50;
        case SECONDS_1:
            tbr = 0b1100;
            apr = 62;
            break;
        case SECONDS_2:
            tbr = 0b1101;
            apr = 62;
            break;
        case SECONDS_5:
            tbr = 0b1110;
            apr = 62;
            break;
        case SECONDS_10:
            tbr = 0b1111;
            apr = 28;
            break;
        case SECONDS_20:
            tbr = 0b1111;
            apr = 42;
            break;
        default: // 30 Seconds
            tbr = 0b1111;
            apr = 62;
            break;
    }

    /* Write prescaler and value to registers*/
    awu->TBR = tbr;
    awu->APR = apr;
}

void awu_sleep(awu_interval_t interval) {

    /* Write prescaler and counter value to registers*/
    _set_interval(interval);

    /* Enable AWU*/
    awu->CSR1 |= AWU_CSR_AWUEN;

    /* Go to sleep */
    halt();
}

void isr_awu(void) __interrupt(ISR_AWU_vect) {
    /* Read AWU CSR to dummy variable clear Interrupt flag (AWUF bit)*/
    volatile uint8_t dummy = awu->CSR1;
}
