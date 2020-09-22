// compile only if in correct env/testing situation
#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include <SPI.h>
#include <WiFi101.h>
#include <pb_arduino.h>
#include "unity.h"
#include "looper.h"

// setup connects serial, runs test cases (upcoming)
// extern void test_valid_decode_request_data();
// extern void test_valid_encode_request_data();
// extern void test_valid_encode_request_max_data();
// extern void test_valid_decode_max_request_data();
extern void test_valid_copy();
extern void test_valid_copy_overflow();
extern void test_single_char_copy();

void printEncryptionType(int thisType)
{
  // read the encryption type and print out the name:
  switch (thisType)
  {
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
  for (uint8_t thisNet = 0; thisNet < numSsid; thisNet++)
  {
    char mac_address[18];
    uint8_t address[18];
    WiFi.BSSID(thisNet, address);
    COPYMAC_TO_STRING(address, mac_address)
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tBSSID: ");
    Serial.print(mac_address);
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
    Serial.flush();
  }
  TEST_ASSERT_TRUE(numSsid > 0);
}

// void test_access_point()
// {
//   TEST_ASSERT_EQUAL_INT(WL_AP_LISTENING, WiFi.beginAP("MKR1000APTEST"));
//   IPAddress ip = WiFi.localIP();
//   IPAddress expected(192, 168, 1, 1);
//   TEST_ASSERT_EQUAL(expected, ip);
// }

// void test_wifi_server()
// {
//   WiFiClient client;
//   pb_istream_s pb_in = as_pb_istream(client);
//   pb_ostream_s pb_out = as_pb_ostream(client);
// }
void setup()
{
  delay(5000);
  UNITY_BEGIN();
  // RUN_TEST(test_valid_decode_request_data);
  // RUN_TEST(test_valid_encode_request_data);
  // RUN_TEST(test_valid_encode_request_max_data);
  // RUN_TEST(test_valid_decode_max_request_data);
  RUN_TEST(test_list_networks);
  // RUN_TEST(test_access_point);
  // RUN_TEST(test_wifi_server);
  // RUN_TEST(test_valid_copy);
  // RUN_TEST(test_valid_copy_overflow);
  // RUN_TEST(test_single_char_copy);
  UNITY_END();
}

void loop()
{
  // nothing to be done here.
}

#endif