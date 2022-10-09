#include "cmsis_os.h"
#include "memory.h"

SPI_HandleTypeDef memory_spi;


void memory_init(GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi) {
	memory_spi = *spi;
	// todo create a stuct for the memory
}

void send_command() {
	uint8_t tx[3] = { 0xAA, 0xAA, 0xAA };
	uint8_t rx[3] = { 0 };

	HAL_GPIO_WritePin(SPI2_CS_MEMORY_GPIO_Port, SPI2_CS_MEMORY_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&memory_spi, tx, rx, (uint16_t) sizeof(tx), 1000);
	HAL_GPIO_WritePin(SPI2_CS_MEMORY_GPIO_Port, SPI2_CS_MEMORY_Pin, GPIO_PIN_SET);

	SEGGER_RTT_WriteString(0, rx[0]);
	SEGGER_RTT_WriteString(0, rx[1]);
	SEGGER_RTT_WriteString(0, rx[2]);
}
