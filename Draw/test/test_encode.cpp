#ifdef UNIT_TEST
#include <unity.h>
#include <encoder.h>
#include <print.h>
void test_valid_encode_request_data()
{
    uint8_t buffer[ArduinoCommand_size];
    ArduinoCommand message = {
        ArduinoCommand_CommandType_BATTERY,
        "SampleNetwork",
        "SampleKey"};
    encode_info info = encode(&message, buffer, ArduinoCommand_size);
    PRINTLN_LOG_RANGE(buffer, info.encode_size);
    PRINTLN_ARRAY_RANGE(buffer, info.encode_size)
    TEST_ASSERT_EQUAL(true, info.status);
    TEST_ASSERT_EQUAL_MEMORY("\x08\x01\x12\x0d\x53\x61\x6d\x70\x6c\x65\x4e\x65\x74\x77\x6f\x72\x6b\x1a\x09\x53\x61\x6d\x70\x6c\x65\x4b\x65\x79", buffer, info.encode_size);
}

void test_valid_encode_request_max_data()
{
    uint8_t buffer[ArduinoCommand_size];
    ArduinoCommand message = {
        ArduinoCommand_CommandType_SCAN,
        "0123456789012345678901234567890", //supports 31 characters + '\0' for end of string
        "0123456789012345678901234567890"};
    encode_info info = encode(&message, buffer, ArduinoCommand_size);
    PRINTLN_LOG_RANGE(buffer, info.encode_size);
    PRINTLN_ARRAY_RANGE(buffer, info.encode_size)
    TEST_ASSERT_EQUAL(true, info.status);
    TEST_ASSERT_EQUAL_MEMORY("\x12\x1f\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x1a\x1f\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x30", buffer, info.encode_size);
}

void test_valid_encode_reply_data()
{
    uint8_t buffer[ArduinoReply_size];
    ArduinoReply reply = {1, {"mac address", "signal strength", "service set id", ArduinoReply_EncryptionType_NONE}, true, {12.0f}};
    encode_info info = encode(&reply, buffer, ArduinoReply_size);
    PRINTLN_LOG_RANGE(buffer, info.encode_size);
    PRINTLN_ARRAY_RANGE(buffer, info.encode_size)
    TEST_ASSERT_EQUAL(true, info.status);
    TEST_ASSERT_EQUAL_MEMORY("\x0a\x2e\x0a\x0b\x6d\x61\x63\x20\x61\x64\x64\x72\x65\x73\x73\x12\x0f\x73\x69\x67\x6e\x61\x6c\x20\x73\x74\x72\x65\x6e\x67\x74\x68\x1a\x0e\x73\x65\x72\x76\x69\x63\x65\x20\x73\x65\x74\x20\x69\x64\x12\x05\x0d\x00\x00\x40\x41", buffer, info.encode_size);
}
#endif