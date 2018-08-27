#ifndef __USART_H_
#define __USART_H_


#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include <stdarg.h>

#define WAIT_TC while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)

void usart_config(void);
void usart_gpio_init(void);
void usart_param_config(void);

void usart_send_string(char *data);
void usart_printf(const char *fmt, ...);

#endif
