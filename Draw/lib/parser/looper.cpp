#include <looper.h>
#include <decoder.h>
#include <SPI.h>
#include <WiFi101.h>
#include <pb_arduino.h>

void copy(char *source, char *destination, size_t length)
{
    strncpy(destination, source, length - 1);
}

ArduinoReply_EncryptionType getEncryptionType(int thisType)
{
    switch (thisType)
    {
    case ENC_TYPE_WEP:
        return ArduinoReply_EncryptionType_WEP;
    case ENC_TYPE_TKIP:
        return ArduinoReply_EncryptionType_WPA;
    case ENC_TYPE_CCMP:
        return ArduinoReply_EncryptionType_WPA2;
    case ENC_TYPE_NONE:
        return ArduinoReply_EncryptionType_NONE;
    case ENC_TYPE_AUTO:
        return ArduinoReply_EncryptionType_AUTO;
    }
}

void list_networks(pb_ostream_s &ostream)
{
    int numSsid = WiFi.scanNetworks();
    ArduinoReply reply;
    reply.has_battery_result = false;
    reply.scan_result_count = numSsid;
    for (int thisNet = 0; thisNet < numSsid; thisNet++)
    {
        uint8_t address[MAC_LENGTH];
        COPYSTRING_TO_STRING(WiFi.SSID(thisNet), reply.scan_result[thisNet].service_set_id);
        COPYINT_TO_STRING(WiFi.RSSI(thisNet), reply.scan_result[thisNet].signal_strength);
        COPYMAC_TO_STRING(WiFi.BSSID(thisNet, address), reply.scan_result[thisNet].mac_address);
        reply.scan_result[thisNet].enc_type = getEncryptionType(WiFi.encryptionType(thisNet));
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