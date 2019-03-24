#ifndef _AWU_H_
#define _AWU_H_

#include "stm8s.h"

void awu_sleep();

void isr_awu(void) __interrupt(1);

#endif // _AWU_H_
