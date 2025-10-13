#include <criterion/criterion.h>
#include "mystring.h"

/* 
 * SCENARIOS:
 * 
 * 1. Initialize a String and Verify it's properties (size = 0, id_error = 0).
 * 2. The phrase must to have null-terminator in.
 */


Test(TestInitializeAString, NewString) {

    struct MyString object;
    init_string(&object);

    cr_assert_eq(object.length, 0, "Expected 0, got %d", object.length);     
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);

    del_string(&object);

}

Test(TestInitializeAString, NullTerminator) {

    struct MyString object;
    init_string(&object);

    cr_assert_eq(object.phrase[0], '\0', "Expected Null Terminator (\'\0\'), got %c", object.phrase[0]);

    del_string(&object);

}