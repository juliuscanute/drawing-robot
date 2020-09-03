#ifdef UNIT_TEST
#include <unity.h>
extern void test_valid_decode_status();
extern void test_valid_encode_status();
#include <unity.h>
int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_decode_status);
    RUN_TEST(test_valid_encode_status);
    UNITY_END();
}
#endif