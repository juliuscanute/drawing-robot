#ifdef UNIT_TEST
#include <unity.h>

#include <decoder.h>

void test_valid_decode_status(){
    uint8_t buffer[128];
    Message message = Message_init_zero;
    message.uniqueId = 100;
    bool status = encode(&message, buffer, 128);
    TEST_ASSERT_EQUAL(true, status);
    TEST_ASSERT_EQUAL_MEMORY("\x08\x64", buffer, 2);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_decode_status);
    UNITY_END();
}

#endif