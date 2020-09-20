// compile only if in correct env/testing situation
#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include "unity.h"

// setup connects serial, runs test cases (upcoming)
extern void test_valid_decode_request_data();
extern void test_valid_encode_request_data();
extern void test_valid_encode_request_max_data();
extern void test_valid_decode_max_request_data();

void printEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
  }
}

void test_list_networks()
{
  int numSsid = WiFi.scanNetworks();
  Serial.print("number of available networks: ");
  Serial.println(numSsid);
  for (int thisNet = 0; thisNet < numSsid; thisNet++)
  {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
    Serial.flush();
  }
  TEST_ASSERT_TRUE(numSsid > 0);
}

void setup()
{
  delay(5000);
  UNITY_BEGIN();
  // RUN_TEST(test_valid_decode_request_data);
  // RUN_TEST(test_valid_encode_request_data);
  // RUN_TEST(test_valid_encode_request_max_data);
  // RUN_TEST(test_valid_decode_max_request_data);
  RUN_TEST(test_list_networks);
  UNITY_END();
}

void loop()
{
  // nothing to be done here.
}

#endif