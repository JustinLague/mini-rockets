#include "app_buzzer.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"
#include "main.h"

const osThreadAttr_t buzzerHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 1024
};

int iBuzzerMode = 3;

void initBuzzerTask() {
	osThreadNew(buzzerTask, NULL, &buzzerHeader_attr);
	SEGGER_RTT_WriteString(0, "Init imu task\r\n");
}

__NO_RETURN void buzzerTask() {

	while(1) {

		switch(iBuzzerMode) {

			case BUZZER_TRIPLETICK:
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
			   osDelay(BEEP_LENGTH);
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
			   osDelay(BEEP_LENGTH);

			case BUZZER_DOUBLETICK:
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
			   osDelay(BEEP_LENGTH);
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
			   osDelay(BEEP_LENGTH);

			case BUZZER_SINGLETICK:
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
			   osDelay(BEEP_LENGTH);
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
			   osDelay(BEEP_LENGTH);

			case BUZZER_IDLE:
			   HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
			   osDelay(CYCLE_TIME);
			   break;

			/* you can have any number of case statements */
			default : /* Optional */
			   iBuzzerMode = 0;
			}

		osDelay(CYCLE_TIME - BEEP_LENGTH);
	}
}

void setBuzzerMode(int _imode) {
	iBuzzerMode = _imode;
}
