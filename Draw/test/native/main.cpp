#ifdef UNIT_TEST
#include <unity.h>
extern void test_valid_decode_request_data();
extern void test_valid_encode_request_data();
extern void test_valid_encode_request_max_data();
extern void test_valid_decode_max_request_data();
extern void test_valid_encode_reply_data();
extern void test_valid_decode_reply_data();

#include <unity.h>
int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_decode_request_data);
    RUN_TEST(test_valid_encode_request_data);
    RUN_TEST(test_valid_encode_request_max_data);
    RUN_TEST(test_valid_decode_max_request_data);
    RUN_TEST(test_valid_encode_reply_data);
    RUN_TEST(test_valid_decode_reply_data);
    UNITY_END();
}
#endif