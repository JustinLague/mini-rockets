#ifndef MEMORY_H_
#define MEMORY_H_

#include "main.h"

/******************************************************************************/
/*                                Define                                      */
/******************************************************************************/
#define READ_CMD 				(uint8_t)0x03
#define HS_READ_CMD 			(uint8_t)0x0B
#define SECTOR_ERASE_4K_CMD 	(uint8_t)0x20
#define SECTOR_ERASE_32K_CMD 	(uint8_t)0x52
#define SECTOR_ERASE_64K_CMD 	(uint8_t)0xD8
#define CHIP_ERASE_CMD 			(uint8_t)0x60
#define BYTE_PROGRAM_CMD 		(uint8_t)0x02
#define AAI_WORD_PROGRAM_CMD 	(uint8_t)0xAD
#define RDSR_CMD 				(uint8_t)0x05
#define EWSR_CMD 				(uint8_t)0x50
#define WRSR_CMD 				(uint8_t)0x01
#define WREN_CMD 				(uint8_t)0x06
#define WRDI_CMD 				(uint8_t)0x04
#define RDID_CMD 				(uint8_t)0x90
#define JDEC_ID_CMD 			(uint8_t)0x9F
#define EBSY_CMD 				(uint8_t)0x70
#define DBSY_CMD 				(uint8_t)0x80


#define JUSTIN_ID 				(uint8_t)0xAA
/******************************************************************************/
/*                             Type  Prototype                                */
/******************************************************************************/
typedef struct {
  GPIO_TypeDef *port;     /** GPIO port of chip select pin */
  uint16_t pin;           /** GPIO pin for chip select */
  SPI_HandleTypeDef *spi; /** SPI handle to use for communication */

  uint8_t current_memory[3];    /** Keep track of where we are writing in the memory */

  uint8_t initialized;
} memory_t;

/******************************************************************************/
/*                             Global variable                                */
/******************************************************************************/


/******************************************************************************/
/*                             Function prototype                             */
/******************************************************************************/
void memory_init(memory_t* memory, GPIO_TypeDef* port, uint16_t pin, SPI_HandleTypeDef* spi);
void finding_start_memory(memory_t* memory);

void read_status_register(memory_t* memory);
void write_enable(memory_t* memory);
void auto_address_increment(memory_t* memory, uint8_t data[]);
void write_disable(memory_t* memory);

void increment_memory(memory_t* memory, uint32_t increment_counter);

#endif /* MEMORY_H_ */
