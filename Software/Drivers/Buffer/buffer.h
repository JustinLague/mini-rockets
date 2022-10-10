/*********************************************************************************************
 ___                  _      ___   _____  ___
 |  _`\               ( )    (  _`\(_   _)(  _`\
 | (_) )   _      ___ | |/') | (_(_) | |  | (_(_)
 | ,  /  /'_`\  /'___)| , <  |  _)_  | |  `\__ \
 | |\ \ ( (_) )( (___ | |\`\ | (_( ) | |  ( )_) |
 (_) (_)`\___/'`\____)(_) (_)(____/' (_)  `\____)
 Copyright (c) 2021-2022
 All rights reserved
 RockETS, Montreal
 Ecole de Technologie Superieure
 *********************************************************************************************/

#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>

// Macros ---------------------------------------------------------------------
#define BUFFER_NEW(x, y) \
    uint8_t x##_data_array[y]; \
    buffer_t x = { \
        .data = x##_data_array, \
        .idx_in = 0, \
        .idx_out = 0, \
        .size = y \
    }

// Structures -----------------------------------------------------------------
typedef struct {
    volatile float *data;
    volatile uint32_t idx_in;
    volatile uint32_t idx_out;
    volatile uint32_t size;
} buffer_t;

// Public prototypes  ---------------------------------------------------------
void buffer_new(buffer_t *buffer, float *data, uint32_t size);

void buffer_push(buffer_t *buffer, float data);

int32_t buffer_count(buffer_t *buffer);

int32_t buffer_size(buffer_t *buffer);

void buffer_flush(buffer_t *buffer);

#endif
