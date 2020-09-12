#ifndef DECODER_H_INCLUDED
#define DECODER_H_INCLUDED
#include "arduino.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_decode.h"
bool decode(ArduinoCommand *message, uint8_t *buffer, size_t length);
#endif