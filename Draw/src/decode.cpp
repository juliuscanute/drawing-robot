#include "arduino.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_decode.h"

void decode() {
  uint8_t buffer[128];
  size_t length = 2;

  Message message = Message_init_zero;

  // Serial.readBytes((char *)buffer, length);

  pb_istream_t stream = pb_istream_from_buffer(buffer, length);

  bool status = pb_decode(&stream, Message_fields, &message);

  if (!status)
  {
      // Serial.println("Failed to encode");
      return;
  }

  // Serial.println(message.uniqueId);
}