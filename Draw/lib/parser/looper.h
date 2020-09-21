#ifndef LOOPER_H_INCLUDED
#define LOOPER_H_INCLUDED
#include <stdio.h>
#include "arduino.pb.h"
#include "encoder.h"
#include "decoder.h"
#define COPYSTRING_TO_STRING(SOURCE, DESTINATION) copy(SOURCE, DESTINATION, sizeof(DESTINATION))
#define COPYINT_TO_STRING(SOURCE, DESTINATION)             \
    {                                                      \
        const char *source_format = "%d";                  \
        memset(DESTINATION, 0, sizeof(DESTINATION));       \
        int sz = snprintf(NULL, 0, source_format, SOURCE); \
        char buf[sz + 1];                                  \
        snprintf(buf, sizeof(buf), source_format, SOURCE); \
        COPYSTRING_TO_STRING(buf, DESTINATION);            \
    }

void copy(char *source, char *destination, size_t length);
void looper(pb_istream_s &istream, pb_ostream_s &ostream);
#endif