#include "cmsis_os.h"
#include "imu.h"
#include "SEGGER_RTT.h"

SPI_HandleTypeDef imu_spi;

void imu_init(imu_t* imu, GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi) {
	imu->pin = pin;
	imu->port = port;
	imu->spi = spi;

	imu->initialized = 1;
}

void read_angular_rate(imu_t * imu) {
	uint8_t tx_X_L[1] = { OUTX_L_G };
	uint8_t rx_X_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_X_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_X_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_X_H[1] = { OUTX_H_G };
	uint8_t rx_X_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_X_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_X_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Y_L[1] = { OUTY_L_G };
	uint8_t rx_Y_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Y_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Y_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Y_H[1] = { OUTY_H_G };
	uint8_t rx_Y_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Y_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Y_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Z_L[1] = { OUTZ_L_G };
	uint8_t rx_Z_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Z_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Z_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Z_H[1] = { OUTZ_H_G };
	uint8_t rx_Z_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Z_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Z_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);
}

void read_acceleration(imu_t * imu) {
	uint8_t tx_X_L[1] = { OUTX_L_XL };
	uint8_t rx_X_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_X_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_X_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_X_H[1] = { OUTX_H_XL };
	uint8_t rx_X_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_X_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_X_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Y_L[1] = { OUTY_L_XL };
	uint8_t rx_Y_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Y_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Y_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Y_H[1] = { OUTY_H_XL };
	uint8_t rx_Y_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Y_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Y_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Z_L[1] = { OUTZ_L_XL };
	uint8_t rx_Z_L[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Z_L, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Z_L, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);

	uint8_t tx_Z_H[1] = { OUTZ_H_XL };
	uint8_t rx_Z_H[1] = { 0x00 };

	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(imu->spi, tx_Z_H, 1, 100);
	HAL_SPI_Receive(imu->spi, rx_Z_H, 1, 100);
	HAL_GPIO_WritePin(imu->port, imu->pin, GPIO_PIN_SET);
}

void read_temp() {

}
