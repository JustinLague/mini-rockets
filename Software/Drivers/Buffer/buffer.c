/**
 * Author 			: Justin Lague
 * Date   			: 2022 ;)
 *
 * brief : Basic functions to manipulate a circular buffer
 */

#include "buffer.h"

// Private prototypes ---------------------------------------------------------

// Public functions -----------------------------------------------------------
/**
 * buffer_new
 *
 * @brief Creates a new buffer and initializes it.
 *
 * @parameters : 	buffer_t *buffer 	Pointer to the buffer to create
 * 				 	uint8_t *data    	Data structure that holds the data
 * 				 	uint32_t size		Size of the buffer to create
 *
 * @return     :	none
 *
 * @Deprecated, use BUFFER_NEW macro
 */
void buffer_new(buffer_t *buffer, float *data, uint32_t size)
{
    buffer->idx_in = 0;
    buffer->idx_out = 0;
    buffer->data = data;
    buffer->size = size;
}

/**
 * buffer_push
 *
 * @brief Pushes new data into the buffer
 *
 * @parameters : 	buffer_t *buffer 	Pointer to the buffer to add data
 * 				 	float ch			Data to push
 *
 * @return     :	int32_t				Number of elements in the buffer after the push
 */
void buffer_push(buffer_t *buffer, float ch)
{
    // Check if buffer is full
    if(buffer->idx_in == buffer->size) {
    	buffer->idx_in = 0;
    }

	// Push data into the buffer and adjust count and indexer
	buffer->data[buffer->idx_in++] = ch;
	buffer->idx_in %= buffer->size;
}

/**
 * buffer_size
 *
 * @brief Gets the size of the buffer
 *
 * @parameters : 	buffer_t *buffer 	Pointer to the buffer to get the size
 *
 * @return     :	int32_t				Size of the buffer
 */
int32_t buffer_size(buffer_t *buffer)
{
    return buffer->size;
}

/**
 * buffer_flush
 *
 * @brief Gets the size of the buffer
 *
 * @parameters : 	buffer_t *buffer 	Pointer to the buffer to flush
 *
 * @return     :	none
 */
void buffer_flush(buffer_t *buffer)
{
	// Flush the buffer
	buffer->idx_out = buffer->idx_in;
}

// Private functions ----------------------------------------------------------

// EOF
