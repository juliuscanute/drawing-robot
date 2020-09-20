#ifdef UNIT_TEST
#include <unity.h>
#include <looper.h>

void test_valid_copy()
{
    char destination[5];
    char *source = "hell";
    copy(source, destination, sizeof(destination));
    TEST_ASSERT_EQUAL_STRING("hell", destination);
}

void test_valid_copy_overflow()
{
    char destination[5];
    char *source = "hellosdfsdfsdfsdfsdfsdfsdf";
    copy(source, destination, sizeof(destination));
    TEST_ASSERT_EQUAL_STRING("hell", destination);
}

void test_single_char_copy()
{
    char destination[5];
    char *source="\0";
    copy(source, destination, sizeof(destination));
    TEST_ASSERT_EQUAL_STRING("", destination);
}

#endif