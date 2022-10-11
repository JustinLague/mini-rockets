#include "barometer.h"
#include "app_barometer.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t barometerHeader_attr = {
  .priority = (osPriority_t) osPriorityHigh, //Set initial thread priority to high
  .stack_size = 1024
};

barometer_t barometer;
SPI_HandleTypeDef baro_hspi1;

/* Definitions for barometer_mutex */
osMutexId_t barometre_mutex_id;

const osMutexAttr_t Barometre_Mutex_attr = {
	"myThreadMutex",                          // human readable mutex name
	osMutexRobust,    				    	  // attr_bits
	NULL,                                     // memory for control block
	0U                                        // size for control block
};

void initBarometerTask(SPI_HandleTypeDef hspi1) {

	baro_hspi1 = hspi1;

	barometre_mutex_id = osMutexNew(&Barometre_Mutex_attr);

	osThreadNew(barometerTask, NULL, &barometerHeader_attr);
	SEGGER_RTT_WriteString(0, "Init barometer task\r\n");
}

__NO_RETURN void barometerTask() {
	barometer_init(&barometer, SPI1_CS_ALTIMITER_GPIO_Port, SPI1_CS_ALTIMITER_Pin, &baro_hspi1);
	barometer_update(&barometer);

	while(1) {
		osMutexAcquire(barometre_mutex_id, 0U);
			barometer_update(&barometer);
		osMutexRelease(barometre_mutex_id);

		osDelay(2);
	}
}

float getPressure() {
	float pressure = 0.0;

		osMutexAcquire(barometre_mutex_id, 0U);
			pressure = barometer.pressure;
		osMutexRelease(barometre_mutex_id);

	return pressure;
}
