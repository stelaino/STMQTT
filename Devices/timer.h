#ifndef __TIMER_H__
#define __TIMER_H__

#include "stm32f10x.h"

void systick_init(void);
void timing_delay_decrement(void);
void delay_us(__IO uint32_t n);

#endif
