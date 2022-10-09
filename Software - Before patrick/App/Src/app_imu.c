#include "app_imu.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"

const osThreadAttr_t imuHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 2048
};


void initIMUTask(SPI_HandleTypeDef hspi1) {
	osThreadId_t imu_id = osThreadNew(IMUTask, NULL, &imuHeader_attr);
	SEGGER_RTT_WriteString(0, "Init imu task\r\n");
}

__NO_RETURN void IMUTask() {

	while(1) {
		osDelay(10);
	}
}
