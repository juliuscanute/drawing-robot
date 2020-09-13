#include <decoder.h>

#define DECODE_FUNCTION_DEF(type)                                 \
  bool decode(type *message, uint8_t *buffer, size_t length)      \
  {                                                               \
    pb_istream_t stream = pb_istream_from_buffer(buffer, length); \
    bool status = pb_decode(&stream, type##_fields, message);     \
    return status;                                                \
  }

DECODE_FUNCTION_DEF(ArduinoCommand)
DECODE_FUNCTION_DEF(ArduinoReply)