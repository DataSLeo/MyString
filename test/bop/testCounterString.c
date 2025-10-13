#include <criterion/criterion.h>
#include "mystring.h"

/**
 * SCENARIOS:
 * 
 * 1. The length of char* is zero 
 * 2. The length of char* is variable
 * 3. The String is NULL
 */


Test(TestCounterString, IsZero) {

    char *buff = (char*) "";
    int length;

    length = counter_string(buff);

    cr_assert_eq(length, 0, "Expected 0, got %d", length);

}

Test(TestCounterString, IsVariable) {

    char *buff = (char*) "Leonardo";
    int length;

    length = counter_string(buff);

    cr_assert_eq(length, 8, "Expected 8, got %d", length);

}

Test(TestCounterString, IsNull) {

    char *buff = NULL;
    int length;

    length = counter_string(buff);

    cr_assert_eq(length, NULL, "Expected NULL, got %d", length);

}