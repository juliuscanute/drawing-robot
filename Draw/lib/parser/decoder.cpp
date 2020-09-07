#include <decoder.h>

bool decode(Message *message, uint8_t *buffer, size_t length) {
  *message = Message_init_zero;
  pb_istream_t stream = pb_istream_from_buffer(buffer, length);
  bool status = pb_decode(&stream, Message_fields, message);
  return status;
}