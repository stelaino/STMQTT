#include "timer.h"
__IO uint32_t gTimingDelay;

/* SystemCoreClock / 1000    --> 1ms */
/* SystemCoreClock / 10000   --> 100us */
/* SystemCoreClock / 100000  --> 10us */
/* SystemCoreClock / 1000000 --> 1us */

void systick_init(void)
{
    while (SysTick_Config(SystemCoreClock / 1000000) == 1);
}

void timing_delay_decrement(void)
{
    if (gTimingDelay != 0x0)
    {
        gTimingDelay--;
    }
}

void SysTick_Handler(void)
{
    timing_delay_decrement();
}

void delay_us(__IO uint32_t n)
{
    gTimingDelay = n;
    while(gTimingDelay != 0);
}
