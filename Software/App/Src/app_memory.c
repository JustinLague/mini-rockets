#include "app_memory.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"
#include "memory.h"

const osThreadAttr_t memoryHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 512
};

SPI_HandleTypeDef memory_hspi2;
memory_t* memory;

void initMemoryTask(SPI_HandleTypeDef hspi2) {
	memory_hspi2 = hspi2;

	osThreadNew(memoryTask, NULL, &memoryHeader_attr);
	SEGGER_RTT_WriteString(0, "Init Memory task\r\n");
}

__NO_RETURN void memoryTask() {
	//TODO: THIS SHOULD WORK ON STM32F405
	//memory_init(&memory, SPI2_CS_MEMORY_GPIO_Port, SPI2_CS_MEMORY_Pin, &memory_hspi2);

	memory_init(&memory, TEST_F446_DEV_BOARD_SPI2_GPIO_Port, TEST_F446_DEV_BOARD_SPI2_Pin, &memory_hspi2);

	//TODO: trouver un moyen d'aller chercher l'information dans _rocketdata surement juste caller une fonction, ensuite doit parser les floats en array de bytes

	while(1) {

		if(memory->initialized != 0) {
			continue;
		}

		osDelay(20);
	}
}
