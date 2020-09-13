#ifdef UNIT_TEST
#include <unity.h>
#include <encoder.h>
#include <print.h>
void test_valid_encode_status()
{
    uint8_t buffer[ArduinoCommand_size];
    ArduinoCommand message = {
        ArduinoCommand_CommandType_BATTERY,
        "SampleNetwork",
        "SampleKey"};
    bool status = encode(&message, buffer, ArduinoCommand_size);
    PRINT_CONST("Encoded buffer: ")
    PRINTLN_LOG(buffer);
    PRINTLN_ARRAY(buffer);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL_MEMORY("\x08\x01\x12\x0d\x53\x61\x6d\x70\x6c\x65\x4e\x65\x74\x77\x6f\x72\x6b\x1a\x09\x53\x61\x6d\x70\x6c\x65\x4b\x65\x79", buffer, 27);
}

#endif