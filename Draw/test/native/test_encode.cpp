#ifdef UNIT_TEST
#include <unity.h>
#include <encoder.h>

void test_valid_encode_status(){
    uint8_t buffer[128];
    Message message = Message_init_zero;
    message.uniqueId = 100;
    bool status = encode(&message, buffer, 128);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL_MEMORY("\x08\x64", buffer, 2);
}

#endif