#ifndef LOOPER_H_INCLUDED
#define LOOPER_H_INCLUDED
#include <stdio.h>
#include "arduino.pb.h"
#include "encoder.h"
#include "decoder.h"
#define MAC_LENGTH 18
#define COPYSTRING_TO_STRING(SOURCE, DESTINATION) copy(SOURCE, DESTINATION, sizeof(DESTINATION))
#define FORMAT_AND_COPY(FORMAT, DESTINATION, ...)          \
    {                                                      \
        memset(DESTINATION, 0, sizeof(DESTINATION));       \
        int sz = snprintf(NULL, 0, FORMAT, ##__VA_ARGS__); \
        char buf[sz + 1];                                  \
        snprintf(buf, sizeof(buf), FORMAT, ##__VA_ARGS__); \
        COPYSTRING_TO_STRING(buf, DESTINATION);            \
    }

#define COPYINT_TO_STRING(SOURCE, DESTINATION)              \
    {                                                       \
        const char *source_format = "%d";                   \
        FORMAT_AND_COPY(source_format, DESTINATION, SOURCE) \
    }
#define COPYMAC_TO_STRING(SOURCE, DESTINATION)                                                                        \
    {                                                                                                                 \
        uint8_t *source = SOURCE;                                                                                     \
        const char *source_format = "%02x:%02x:%02x:%02x:%02x:%02x";                                                  \
        FORMAT_AND_COPY(source_format, DESTINATION, source[0], source[1], source[2], source[3], source[4], source[5]) \
    }

void copy(char *source, char *destination, size_t length);
void looper(pb_istream_s &istream, pb_ostream_s &ostream);
#endif