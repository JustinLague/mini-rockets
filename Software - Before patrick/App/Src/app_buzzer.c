#include "app_buzzer.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t buzzerHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 1024
};


void initBuzzerTask() {
	osThreadId_t buzzer_id = osThreadNew(buzzerTask, NULL, &buzzerHeader_attr);
	SEGGER_RTT_WriteString(0, "Init imu task\r\n");
}

__NO_RETURN void buzzerTask() {

	while(1) {
		osDelay(10);
	}
}
