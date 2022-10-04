#include "app_memory.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t memoryHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 2048
};


void initMemoryTask(SPI_HandleTypeDef hspi2) {
	osThreadId_t memory_id = osThreadNew(memoryTask, NULL, &memoryHeader_attr);
	SEGGER_RTT_WriteString(0, "Init Memory task\r\n");
}

__NO_RETURN void memoryTask() {

	while(1) {
		osDelay(10);
	}
}
