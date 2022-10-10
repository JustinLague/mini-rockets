#include "app_heartbeat.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t heartbeatHeader_attr = {
  .priority = (osPriority_t) osPriorityIdle, //Set initial thread priority to high
  .stack_size = 512
};


void initHeartbeatTask() {
	osThreadNew(heartbeatTask, NULL, &heartbeatHeader_attr);
	SEGGER_RTT_WriteString(0, "Init heartbeat task\r\n");
}

__NO_RETURN void heartbeatTask() {

	while(1) {
		osDelay(10);
	}
}
