#include <encoder.h>

#define ENCODE_FUNCTION_DEF(type)                                                \
  bool encode(const type *message, uint8_t *buffer, size_t buffer_size)          \
  {                                                                              \
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, buffer_size);           \
    bool status = pb_encode(&stream, type##_fields, message);                    \
    size_t encode_size = 0;                                                      \
    status = status & pb_get_encoded_size(&encode_size, type##_fields, message); \
    buffer[encode_size] = '\0';                                                  \
    return status;                                                               \
  }

ENCODE_FUNCTION_DEF(ArduinoCommand)
ENCODE_FUNCTION_DEF(ArduinoReply)