#ifdef UNIT_TEST
#include <unity.h>
#include <encoder.h>

void test_valid_encode_status(){
    uint8_t buffer[128];
    ArduinoCommand message = ArduinoCommand_init_zero;
    message.command = ArduinoCommand_CommandType_BATTERY;
    bool status = encode(&message, buffer, 128);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL_MEMORY("\x08\x01", buffer, 2);
}

#endif