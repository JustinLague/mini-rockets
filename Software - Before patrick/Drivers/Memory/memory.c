#include "cmsis_os.h"
#include "memory.h"

void memory_init(GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi) {
// todo create a stuct for the memory
}

void send_command() {
	uint8_t tx[3] = { ((uint8_t) (PROM_READ_COMMAND + coefficient * 2)), 0, 0 };
	uint8_t rx[3] = { 0 };

	HAL_GPIO_WritePin(barometer->port, barometer->pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(barometer->spi, tx, rx, (uint16_t) sizeof(tx), 1000);
	HAL_GPIO_WritePin(barometer->port, barometer->pin, GPIO_PIN_SET);

	SEGGER_RTT_WriteString(0, rx[0]);
	SEGGER_RTT_WriteString(0, rx[1]);
	SEGGER_RTT_WriteString(0, rx[2]);
}
