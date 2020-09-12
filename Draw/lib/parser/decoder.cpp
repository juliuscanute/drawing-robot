#include <decoder.h>

bool decode(ArduinoCommand *message, uint8_t *buffer, size_t length) {
  *message = ArduinoCommand_init_zero;
  pb_istream_t stream = pb_istream_from_buffer(buffer, length);
  bool status = pb_decode(&stream, ArduinoCommand_fields, message);
  return status;
}