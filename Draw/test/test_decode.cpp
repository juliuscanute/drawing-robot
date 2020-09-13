#ifdef UNIT_TEST
#include <unity.h>
#include <decoder.h>

void test_valid_decode_request_data()
{
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x08', '\x01', '\x12', '\x0d', '\x53', '\x61', '\x6d', '\x70', '\x6c', '\x65', '\x4e', '\x65', '\x74', '\x77', '\x6f', '\x72', '\x6b', '\x1a', '\x09', '\x53', '\x61', '\x6d', '\x70', '\x6c', '\x65', '\x4b', '\x65', '\x79'};
    bool status = decode(&message, buffer, 28);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_BATTERY, message.command);
    TEST_ASSERT_EQUAL_STRING("SampleNetwork", message.service_set_id);
    TEST_ASSERT_EQUAL_STRING("SampleKey", message.network_key);
}

void test_valid_decode_max_request_data()
{
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x12', '\x1f', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x1a', '\x1f', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30'};
    bool status = decode(&message, buffer, 66);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_SCAN, message.command);
    TEST_ASSERT_EQUAL_STRING("0123456789012345678901234567890", message.service_set_id);
    TEST_ASSERT_EQUAL_STRING("0123456789012345678901234567890", message.network_key);
}

#endif