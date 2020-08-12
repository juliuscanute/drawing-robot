#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include "arduino.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_encode.h"
bool encode(const Message *message, uint8_t *buffer, size_t buffer_size);
#endif