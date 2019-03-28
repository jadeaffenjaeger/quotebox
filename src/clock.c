#include "clock.h"

static volatile struct clk_t * const clk = (struct clk_t *) CLK_BASE;

void clock_init() {
    /* Set clock to 250kHz to save some energy*/
    clk->CKDIVR = 0b110;

    /* Disable peripheral clocks*/
    /* clk->PCKENR1 = 0x00;*/
    /* clk->PCKENR2 = 0x00;*/

    /* Enable UART*/
    /* clk->PCKENR1 |= (CLK_PCKENR1_PCKEN13);*/

    /* Enable AWU*/
    /* clk->PCKENR2 |= (CLK_PCKENR2_PCKEN22);*/
}
