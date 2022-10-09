#include "app_main.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t mainHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 4096
};


void initMainTask() {
	osThreadId_t main_id = osThreadNew(mainTask, NULL, &mainHeader_attr);
	SEGGER_RTT_WriteString(0, "Init main task\r\n");
}

__NO_RETURN void mainTask() {

	while(1) {
		osDelay(1000);
	}
}
