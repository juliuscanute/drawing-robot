#ifdef UNIT_TEST
#include <unity.h>
#include <decoder.h>

void test_valid_decode_status(){
    Message message = Message_init_zero;
    uint8_t buffer[] = {'\x08', '\x64'};
    bool status = decode(&message, buffer, 2);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL(100, message.uniqueId);
}

#endif