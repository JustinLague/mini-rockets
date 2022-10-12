#ifndef IMU_H_
#define IMU_H_

#include "main.h"

/******************************************************************************/
/*                                Define                                      */
/******************************************************************************/
#define OUT_TEMP_L				(uint8_t)0x20 // Temperature Low
#define OUT_TEMP_H 			    (uint8_t)0x21 // Temperature High
#define OUTX_L_G 			    (uint8_t)0x22 // Gyroscope X Low
#define OUTX_H_G 				(uint8_t)0x23 // Gyroscope X High
#define OUTY_L_G 	            (uint8_t)0x24 // Gyroscope Y Low
#define OUTY_H_G	 			(uint8_t)0x25 // Gyroscope Y High
#define OUTZ_L_G 				(uint8_t)0x26 // Gyroscope Z Low
#define OUTZ_H_G 				(uint8_t)0x27 // Gyroscope Z High
#define OUTX_L_XL				(uint8_t)0x28 // Acceleration X Low
#define OUTX_H_XL 				(uint8_t)0x29 // Acceleration X High
#define OUTY_L_XL				(uint8_t)0x2A // Acceleration Y Low
#define OUTY_H_XL 				(uint8_t)0x2B // Acceleration Y High
#define OUTZ_L_XL 				(uint8_t)0x2C // Acceleration Z Low
#define OUTZ_H_XL				(uint8_t)0x2D // Acceleration Z High

#define X_OFS_USR				(uint8_t)0x73 // Acceleration X offset
#define Y_OFS_USR				(uint8_t)0x74 // Acceleration Y offset
#define Z_OFS_USR				(uint8_t)0x75 // Acceleration Z offset

/******************************************************************************/
/*                             Type  Prototype                                */
/******************************************************************************/
typedef struct {
    GPIO_TypeDef *port;     /** GPIO port of chip select pin */
    uint16_t pin;           /** GPIO pin for chip select */
    SPI_HandleTypeDef *spi; /** SPI handle to use for communication */

    uint8_t initialized;

  	uint8_t angular_rate[6];
    uint8_t acceleration[6];

} imu_t;

/******************************************************************************/
/*                             Global variable                                */
/******************************************************************************/


/******************************************************************************/
/*                             Function prototype                             */
/******************************************************************************/
void imu_init(imu_t* memory, GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi);

void read_angular_rate();
void read_acceleration();
void read_temp();

#endif /* IMU_H_ */
