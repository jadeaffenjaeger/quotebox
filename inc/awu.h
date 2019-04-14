#ifndef _AWU_H_
#define _AWU_H_

#include "stm8s.h"

typedef enum awu_interval {
    MSECONDS_100,
    SECONDS_1,
    SECONDS_2,
    SECONDS_5,
    SECONDS_10,
    SECONDS_20,
    SECONDS_30
} awu_interval_t;

void awu_sleep(awu_interval_t interval);

void isr_awu(void) __interrupt(ISR_AWU_vect);

#endif // _AWU_H_
