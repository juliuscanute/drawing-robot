#include <looper.h>
#include <decoder.h>
#include <SPI.h>
#include <WiFi101.h>
#include <pb_arduino.h>

void copy(char *source, char *destination, size_t length)
{
    memset(destination, 0, length);
    strncpy(destination, source, length - 1);
}

// void test_list_networks()
// {
//   int numSsid = WiFi.scanNetworks();
//   Serial.print("number of available networks: ");
//   Serial.println(numSsid);
//   for (int thisNet = 0; thisNet < numSsid; thisNet++)
//   {
//     Serial.print(thisNet);
//     Serial.print(") ");
//     Serial.print(WiFi.SSID(thisNet));
//     Serial.print("\tSignal: ");
//     Serial.print(WiFi.RSSI(thisNet));
//     Serial.print(" dBm");
//     Serial.print("\tEncryption: ");
//     printEncryptionType(WiFi.encryptionType(thisNet));
//     Serial.flush();
//   }
//   TEST_ASSERT_TRUE(numSsid > 0);
// }

void list_networks(pb_ostream_s &ostream)
{
    int numSsid = WiFi.scanNetworks();
    ArduinoReply reply;
    reply.has_battery_result = false;
    reply.scan_result_count = numSsid;
    for (int thisNet = 0; thisNet < numSsid; thisNet++)
    {
        COPYSTRING_TO_STRING(WiFi.SSID(thisNet), reply.scan_result[thisNet].service_set_id);
        COPYINT_TO_STRING(WiFi.RSSI(thisNet), reply.scan_result[thisNet].signal_strength);
    }
}

void looper(pb_istream_s &istream, pb_ostream_s &ostream)
{
    ArduinoCommand message = ArduinoCommand_init_zero;
    decode(&message, istream);
    ArduinoCommand_CommandType command = message.command;
    switch (command)
    {
    case ArduinoCommand_CommandType_SCAN:
        list_networks(ostream);
        break;
    default:;
    }
}