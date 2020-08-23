#include "encoder.h"

bool encode(const Message *message, uint8_t *buffer, size_t buffer_size) {
  pb_ostream_t stream = pb_ostream_from_buffer(buffer, buffer_size);
  bool status = pb_encode(&stream, Message_fields, message);
  size_t encode_size = 0;
  status = status & pb_get_encoded_size(&encode_size, Message_fields, message);
  buffer[encode_size] = '\0';
  return status;
}