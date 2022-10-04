#include "barometer.h"
#include "app_barometer.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t barometerHeader_attr = {
  .priority = (osPriority_t) osPriorityHigh, //Set initial thread priority to high
  .stack_size = 2048
};


void initBarometerTask(SPI_HandleTypeDef hspi1) {
	osThreadId_t barometer_id = osThreadNew(barometerTask, NULL, &barometerHeader_attr);
	SEGGER_RTT_WriteString(0, "Init barometer task\r\n");
}

__NO_RETURN void barometerTask() {
	while(1) {
		osDelay(10);
	}
}
