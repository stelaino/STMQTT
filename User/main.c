#include "stm32f10x.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "usart1.h"
#include "usart2.h"
#include "utils.h"
#include "esp8266.h"
#include "hal_i2c.h"
#include "mqtt_loop.h"
#include "timer.h"

int main(void)
{
    USART1_Init();
    USART2_Init();
		SystemInit();
		systick_init();
    mDelay(1000);
    Hal_I2C_Init();
    /*初始化8266，并连接CWJAP配置的AP，与MQTT_CIPSTART配置的服务器建立TCP连接*/
    ESP8266_Init((int8_t *)MQTT_CIPSTART, (int8_t *)CWJAP);
    /*进入MQTT协议测试主循环*/
    MQTT_Loop();
}