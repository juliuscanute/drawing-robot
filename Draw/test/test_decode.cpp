#ifdef UNIT_TEST
#include <unity.h>
#include <decoder.h>

void test_valid_decode_status(){
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x08','\x01','\x12','\x0d','\x53','\x61','\x6d','\x70','\x6c','\x65','\x4e','\x65','\x74','\x77','\x6f','\x72','\x6b','\x1a','\x09','\x53','\x61','\x6d','\x70','\x6c','\x65','\x4b','\x65','\x79'};
    bool status = decode(&message, buffer, 28);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_BATTERY, message.command);
    TEST_ASSERT_EQUAL_STRING("SampleNetwork", message.service_set_id);
    TEST_ASSERT_EQUAL_STRING("SampleKey", message.network_key);
}

#endif