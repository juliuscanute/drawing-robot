#ifdef UNIT_TEST
#include <unity.h>
#include <decoder.h>

void test_valid_decode_status(){
    ArduinoCommand message = ArduinoCommand_init_zero;
    uint8_t buffer[] = {'\x08', '\x01'};
    bool status = decode(&message, buffer, 2);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(ArduinoCommand_CommandType_BATTERY, message.command);
}

#endif