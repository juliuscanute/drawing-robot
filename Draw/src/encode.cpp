#include "arduino.pb.h"
#include "pb_common.h"
#include "pb.h"
#include "pb_encode.h"

void encode(){
  uint8_t buffer[128];

  Message message = Message_init_zero;

  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

  message.uniqueId = 1;

  bool status = pb_encode(&stream, Message_fields, &message);

  if (!status)
  {
      // Serial.println("Failed to encode");
      return;
  }
  // Serial.write(buffer, stream.bytes_written);
}