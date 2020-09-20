#include <decoder.h>

#define DECODE_FUNCTION_DEF(type)                             \
  bool decode(type *message, pb_istream_s &stream)             \
  {                                                           \
    bool status = pb_decode(&stream, type##_fields, message); \
    return status;                                            \
  }

DECODE_FUNCTION_DEF(ArduinoCommand)
DECODE_FUNCTION_DEF(ArduinoReply)