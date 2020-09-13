#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED
#include "arduino.pb.h"
#include "arduino_reply.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_decode.h"
#define DECODE_FUNCTION_DEC(type) \
    bool decode(type *message, uint8_t *buffer, size_t length);
DECODE_FUNCTION_DEC(ArduinoCommand)
DECODE_FUNCTION_DEC(ArduinoReply)
#endif