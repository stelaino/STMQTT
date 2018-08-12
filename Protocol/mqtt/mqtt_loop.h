#include "mqtt.h"
#include <string.h>
#include "utils.h"
#include "stm32f10x.h"

#ifdef WIN32
#error Not support Windows now.
#endif // WIN32

#include <string.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "usart2.h"

#define DS_TO_PUBLISH "mqtt_msg"

#define DS_TO_PUBLISH_T "mqtt_msg_t"

#define DS_TO_PUBLISH_RH "mqtt_msg_rh"

#define TOPIC_TO_SUB "132085/sucavEg3rsFzCDo5MDiHURAhzo8=/29621524/caramel"
#define PACK_FALG_UNSUB 11
#define TOPIC_TO_UNSUB "132085/sucavEg3rsFzCDo5MDiHURAhzo8=/29621524/caramel"

#define TIME_OUT 1
#define EVENT 2

#define MQTT_DEVICE_PROJ_ID "132085"
#define MQTT_DEVICE_ID "29621524"
#define MQTT_DEVICE_API_KEY  "sucavEg3rsFzCDo5MDiHURAhzo8="

void MQTT_Loop(void);
