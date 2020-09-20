#include "encoder.h"
#include "decoder.h"
#include "looper.h"

#if defined(ARDUINO) && !defined(UNIT_TEST)
#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(1000);
}

#else
int main()
{
  return 0;
}
#endif
