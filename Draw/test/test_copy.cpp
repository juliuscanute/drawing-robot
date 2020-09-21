#ifdef UNIT_TEST
#include <unity.h>
#include <looper.h>

void test_valid_copy()
{
    char destination[5];
    char *source = "hell";
    COPYSTRING_TO_STRING(source, destination);
    TEST_ASSERT_EQUAL_STRING("hell", destination);
    int number_source = 1234567890;
    char number_destination[11];
    COPYINT_TO_STRING(number_source, number_destination);
    TEST_ASSERT_EQUAL_STRING("1234567890", number_destination);
}

void test_valid_copy_overflow()
{
    char destination[5];
    char *source = "hellosdfsdfsdfsdfsdfsdfsdf";
    COPYSTRING_TO_STRING(source, destination);
    TEST_ASSERT_EQUAL_STRING("hell", destination);
    {
        int number_source = 1234567890;
        char number_destination[3];
        COPYINT_TO_STRING(number_source, number_destination);
        TEST_ASSERT_EQUAL_STRING("12", number_destination);
    }
    {
        int number_source = -1;
        char number_destination[3];
        COPYINT_TO_STRING(number_source, number_destination);
        TEST_ASSERT_EQUAL_STRING("-1", number_destination);
    }
}

void test_single_char_copy()
{
    char destination[5];
    char *source = "\0";
    COPYSTRING_TO_STRING(source, destination);
    TEST_ASSERT_EQUAL_STRING("", destination);
    int number_source = 0;
    char number_destination[3];
    COPYINT_TO_STRING(number_source, number_destination);
    TEST_ASSERT_EQUAL_STRING("0", number_destination);
}

#endif