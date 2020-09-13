#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
#include "arduino.pb.h"
#include "arduino_reply.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_encode.h"
#define ENCODE_FUNCTION_DEC(type)                                          \
    bool encode(const type *message, uint8_t *buffer, size_t buffer_size);
ENCODE_FUNCTION_DEC(ArduinoCommand)
ENCODE_FUNCTION_DEC(ArduinoReply)
#endif