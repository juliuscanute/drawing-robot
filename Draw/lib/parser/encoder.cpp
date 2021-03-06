#include <encoder.h>
#include <print.h>

#define ENCODE_FUNCTION_DEF(type)                                                     \
  encode_info encode(const type *message, pb_ostream_t &stream)                        \
  {                                                                                   \
    bool status = pb_encode(&stream, type##_fields, message);                         \
    size_t encode_size = 0;                                                           \
    encode_info info;                                                                 \
    info.status = status & pb_get_encoded_size(&encode_size, type##_fields, message); \
    info.encode_size = encode_size;                                                   \
    return info;                                                                      \
  }

ENCODE_FUNCTION_DEF(ArduinoCommand)
ENCODE_FUNCTION_DEF(ArduinoReply)