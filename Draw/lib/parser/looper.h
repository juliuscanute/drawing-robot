#ifndef LOOPER_H_INCLUDED
#define LOOPER_H_INCLUDED
#include "arduino.pb.h"
#include "encoder.h"
#include "decoder.h"
void copy(char *source, char *destination, size_t length);
void looper(pb_istream_s &istream, pb_ostream_s &ostream);
#endif