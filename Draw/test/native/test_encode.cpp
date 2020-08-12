#ifdef UNIT_TEST

#include <unity.h>

#include <encoder.h>

void test_encode(){
    uint8_t buffer[128];
    Message message = Message_init_zero;
    message.uniqueId = 100;
    bool status = encode(&message, buffer, 128);
    TEST_ASSERT_EQUAL(status, true);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_encode);
    UNITY_END();
}

#endif