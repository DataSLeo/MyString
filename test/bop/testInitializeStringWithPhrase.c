#include <criterion/criterion.h>
#include "mystring.h"

/** 
 * SCENARIES:
 * 
 * 1. Phrase is empty and has \0
 * 2. String was filled correctly
 */


Test(testInitializeStringWithPhrase, IsEmpty) {

    struct MyString object;
    initwp_string(&object, (char*)"");

    cr_assert_eq(object.length, 0, "Expected 0, got %d", object.length);
    cr_assert_eq(object.phrase[0], '\0', "Expected Null Terminator (\'\0\'), got %c", object.phrase[0]);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);

    del_string(&object);

}

Test(testInitializeStringWithPhase, Phrase) {

    struct MyString object;
    initwp_string(&object, (char*)"hello, world!");

    cr_assert_eq(object.length, 13, "Expected 13, got %d", object.length);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);

    del_string(&object);

}