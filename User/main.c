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
    /*��ʼ��8266��������CWJAP���õ�AP����MQTT_CIPSTART���õķ���������TCP����*/
    ESP8266_Init((int8_t *)MQTT_CIPSTART, (int8_t *)CWJAP);
    /*����MQTTЭ�������ѭ��*/
    MQTT_Loop();
}