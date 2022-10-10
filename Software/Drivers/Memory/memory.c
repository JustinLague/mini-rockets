#include "cmsis_os.h"
#include "memory.h"
#include "SEGGER_RTT.h"

SPI_HandleTypeDef memory_spi;

osSemaphoreId_t received_read_data;


void memory_init(memory_t* memory, GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi) {

	memory->pin = pin;
	memory->port = port;
	memory->spi = spi;
	memory->current_memory[0] = 0x00;
	memory->current_memory[1] = 0x00;
	memory->current_memory[2] = 0x00;
	memory->initialized = 0;

	received_read_data = osSemaphoreNew(1, 0, NULL);

	finding_start_memory(memory);

	memory->initialized = 1;
}

void finding_start_memory(memory_t* memory) {
	uint8_t tx[5] = { HS_READ_CMD, 0x00, 0x00, 0x00 };
	uint8_t rx[64];

	uint8_t continue_reading = 1;
	uint32_t increment_counter = 0;

	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(memory->spi, tx, 1, 100);

	//might need hold here need to test if I dont skip some bits when reading the whole 64 bits

	while(continue_reading) {
		HAL_SPI_Receive_IT(memory->spi, rx, 64);
		osSemaphoreAcquire(received_read_data, osWaitForever);

		increment_counter++;

		if((rx[0] | JUSTIN_ID) != JUSTIN_ID) {
			continue_reading = 0;
		}
	}

	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);

	increment_memory(memory, increment_counter);
}

void write_enable(memory_t* memory) {
	uint8_t tx[1] = { WREN_CMD };

	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(memory->spi, tx, 1, 100);
	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);
}

void write_disable(memory_t* memory) {
	uint8_t tx[1] = { WRDI_CMD };

	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(memory->spi, tx, 1, 100);
	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);
}


void read_status_register(memory_t* memory) {
	uint8_t tx[1] = { DBSY_CMD };
	uint8_t rx[1] = { 0x0 };

	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(memory->spi, tx, 1, 100);
	HAL_SPI_Receive(memory->spi, rx, 1, 100);
	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);
}

void auto_address_increment(memory_t* memory, uint8_t data[]) {
	write_enable(memory);

	uint8_t dataSentCounter = 0;

	// preparing command to put the memoring in AAI mode TODO: CHANGE 0x00, 0x01, 0x02 pour l'address de memory de depart
	uint8_t txAAICMD[6] = { AAI_WORD_PROGRAM_CMD, memory->current_memory[2], memory->current_memory[1], memory->current_memory[0], data[dataSentCounter], data[dataSentCounter] };

	//initiate the memory in AAI and sending the first 2 set of data;
	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(memory->spi, txAAICMD, 1, 100);
	HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);

	dataSentCounter += 2;

	// preparing command to check if the memory is busy
	uint8_t txStatus[2] = { AAI_WORD_PROGRAM_CMD, 0xFF };
	uint8_t rxStatus[2] = { 0xFF, 0xFF };

	while(dataSentCounter != 64) {

		//check if memory is busy
		while(rxStatus[1] & 0x100) {
			HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
			HAL_SPI_TransmitReceive(memory->spi, txStatus, rxStatus, 2, 100);
			HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);
		}

		//prepare the next set of data
		uint8_t txData[3] = { AAI_WORD_PROGRAM_CMD, data[dataSentCounter], data[dataSentCounter + 1] };

		//send the next set of data
		HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(memory->spi, txData, 3, 100);
		HAL_GPIO_WritePin(memory->port, memory->pin, GPIO_PIN_SET);

		//increment the counter
		dataSentCounter += 2;
	}

	increment_memory(memory, 1);

	write_disable(memory);
	read_status_register(memory);
}


void increment_memory(memory_t* memory, uint32_t increment_counter) {
	uint32_t memory_address = (memory->current_memory[0] << 16) + (memory->current_memory[1] << 8) + memory->current_memory[2];

	memory_address += (512 * increment_counter);

	memory->current_memory[0] = (memory_address >> 16) & 0xFF;
	memory->current_memory[1] = (memory_address >> 8) & 0xFF;
	memory->current_memory[2] = (memory_address >> 0) & 0xFF;

	//maybe ajouter un check pour s'assurer qu'on depasse pas la memoire
}

// Interrupt Tx
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef * hspi) {

}

// Interrupt Rx
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef * hspi) {
	osSemaphoreRelease(received_read_data);
}

// Interrupt TxRx
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef * hspi) {

}
