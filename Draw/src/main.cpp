#include "encoder.h"
#include "decoder.h"

#ifndef UNIT_TEST
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
}
#endif
