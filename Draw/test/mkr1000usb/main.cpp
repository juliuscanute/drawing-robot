// compile only if in correct env/testing situation
#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include "unity.h"

// setup connects serial, runs test cases (upcoming)
extern void test_valid_decode_request_data();
extern void test_valid_encode_request_data();
extern void test_valid_encode_request_max_data();
extern void test_valid_decode_max_request_data();

void test_mod1() {
        
}

void setup() {
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(test_valid_decode_request_data);
  RUN_TEST(test_valid_encode_request_data);
  RUN_TEST(test_valid_encode_request_max_data);
  RUN_TEST(test_valid_decode_max_request_data);
  UNITY_END();
}

void loop() {
  // nothing to be done here.
}

#endif