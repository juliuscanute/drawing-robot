#ifdef UNIT_TEST
#include <unity.h>
#include <decoder.h>

void test_valid_decode_request_data()
{
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x08', '\x01', '\x12', '\x0d', '\x53', '\x61', '\x6d', '\x70', '\x6c', '\x65', '\x4e', '\x65', '\x74', '\x77', '\x6f', '\x72', '\x6b', '\x1a', '\x09', '\x53', '\x61', '\x6d', '\x70', '\x6c', '\x65', '\x4b', '\x65', '\x79'};
    pb_istream_s stream = pb_istream_from_buffer(buffer, 28);
    bool status = decode(&message, stream);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_BATTERY, message.command);
    TEST_ASSERT_EQUAL_STRING("SampleNetwork", message.service_set_id);
    TEST_ASSERT_EQUAL_STRING("SampleKey", message.network_key);
}

void test_valid_decode_max_request_data()
{
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x12', '\x1f', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x1a', '\x1f', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30', '\x31', '\x32', '\x33', '\x34', '\x35', '\x36', '\x37', '\x38', '\x39', '\x30'};
    pb_istream_s stream = pb_istream_from_buffer(buffer, 66);
    bool status = decode(&message, stream);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_SCAN, message.command);
    TEST_ASSERT_EQUAL_STRING("0123456789012345678901234567890", message.service_set_id);
    TEST_ASSERT_EQUAL_STRING("0123456789012345678901234567890", message.network_key);
}

void test_valid_decode_reply_data()
{
    ArduinoReply reply = ArduinoReply_init_zero;
    memset(&reply, 0xAA, sizeof(reply));
    uint8_t buffer[] = {'\x0a','\x2e','\x0a','\x0b','\x6d','\x61','\x63','\x20','\x61','\x64','\x64','\x72','\x65','\x73','\x73','\x12','\x0f','\x73','\x69','\x67','\x6e','\x61','\x6c','\x20','\x73','\x74','\x72','\x65','\x6e','\x67','\x74','\x68','\x1a','\x0e','\x73','\x65','\x72','\x76','\x69','\x63','\x65','\x20','\x73','\x65','\x74','\x20','\x69','\x64','\x12','\x05','\x0d','\x00','\x00','\x40','\x41'};
    pb_istream_s stream = pb_istream_from_buffer(buffer, 55);
    bool status = decode(&reply, stream);
    TEST_ASSERT_EQUAL(true, status);
}

#endif