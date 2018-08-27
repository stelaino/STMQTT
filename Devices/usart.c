#include "usart.h"

void usart_config(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    
    usart_gpio_init();
    usart_param_config();
}

void usart_gpio_init(void)
{
    GPIO_InitTypeDef g;
    g.GPIO_Speed = GPIO_Speed_50MHz;
    
    g.GPIO_Pin = GPIO_Pin_9;
    g.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出
    GPIO_Init(GPIOA, &g);
    
    g.GPIO_Pin = GPIO_Pin_10;
    g.GPIO_Mode = GPIO_Mode_IN_FLOATING; //开漏输入
    GPIO_Init(GPIOA, &g);
}

void usart_param_config(void)
{
    USART_InitTypeDef u;
    
    u.USART_BaudRate = 9600;
    u.USART_WordLength = USART_WordLength_8b;   //数据位8位
    u.USART_StopBits = USART_StopBits_1;    //停止位1位
    u.USART_Parity = USART_Parity_No;   //无校验位
    u.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    u.USART_Mode = USART_Mode_Tx;
    
    USART_Init(USART1, &u);
    
    USART_Cmd(USART1, ENABLE);
}

void usart_send_string(char *data)
{
    char *p = data;
    while (p < data + strlen(data))
    {
        WAIT_TC;
        USART_SendData(USART1, *p++);
    }
}

void usart_printf(const char *fmt, ...)
{
    va_list ap;
    char string[64];
    
    va_start(ap, fmt);
    vsprintf(string, fmt, ap);
    va_end(ap);
    usart_send_string(string);
}
