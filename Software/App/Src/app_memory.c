#include "app_memory.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"
#include "memory.h"

const osThreadAttr_t memoryHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 2048
};

SPI_HandleTypeDef memory_hspi2;

void initMemoryTask(SPI_HandleTypeDef hspi2) {
	memory_hspi2 = hspi2;

	osThreadNew(memoryTask, NULL, &memoryHeader_attr);
	SEGGER_RTT_WriteString(0, "Init Memory task\r\n");
}

__NO_RETURN void memoryTask() {

	memory_init(SPI2_CS_MEMORY_GPIO_Port, SPI2_CS_MEMORY_Pin, &memory_hspi2);

	while(1) {

		send_command();
		osDelay(20);
	}
}
