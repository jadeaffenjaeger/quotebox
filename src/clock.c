#include "clock.h"

static volatile struct clk_t * const clk = (struct clk_t *) CLK_BASE;

void clock_init() {
    /* Set clock to 16MHz*/
    clk->CKDIVR = 0x00;
}
