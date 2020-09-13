#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
#ifndef ARDUINO
#include <cstdio>
#define PRINTLN_ENCODE_SIZE(buffer) \
    {                               \
        size_t i = 0;               \
        while (buffer[i] != '\0')   \
            i++;                    \
        printf("%d\n", i);          \
    }

#define PRINTLN_LOG(buffer)                    \
    for (size_t i = 0; buffer[i] != '\0'; ++i) \
    {                                          \
        printf("\\x%.2x", buffer[i]);          \
    }                                          \
    printf("\n");
#define PRINT_CONST(value)        \
    {                             \
        const char *text = value; \
        printf("%s", text);       \
    }
#define PRINTLN_ARRAY(buffer)                  \
    printf("{");                               \
    for (size_t i = 0; buffer[i] != '\0'; ++i) \
    {                                          \
        if (i > 0)                             \
        {                                      \
            printf(",");                       \
        }                                      \
        printf("\'\\x%.2x\'", buffer[i]);      \
    }                                          \
    printf("}");                               \
    printf("\n");
#else
#define PRINTLN_ENCODE_SIZE(buffer) \
    {                               \
    }
#define PRINTLN_LOG(buffer) \
    {                       \
    }
#define PRINT_CONST(value) \
    {                      \
    }
#define PRINTLN_ARRAY(buffer) \
    {                         \
    }
#endif
#endif