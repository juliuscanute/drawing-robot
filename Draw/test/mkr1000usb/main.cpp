// compile only if in correct env/testing situation
#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include "unity.h"

// setup connects serial, runs test cases (upcoming)
extern void test_valid_decode_status();
extern void test_valid_encode_status();

void test_mod1() {
        
}

void setup() {
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(test_valid_decode_status);
  RUN_TEST(test_valid_encode_status);
  UNITY_END();
}

void loop() {
  // nothing to be done here.
}

#endif