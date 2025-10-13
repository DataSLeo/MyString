#include <criterion/criterion.h>
#include "mystring.h"


/* SCENARIOS:
 *
 * 1. After use del_string the size property must be Zero 
 * 2. After use del_string the phrase property must be Null
 * 3. After use del_string the id_error must be MYSTRING_NONE
 * 4. Try use del_string again makes a id_error 
*/


Test(FreeAString, SizeIsZero) {

    struct MyString object;
    init_string(&object);

    del_string(&object);

    cr_assert_eq(object.length, 0, "Expected 0, got %d", object.length);
        
}

Test(FreeAString, PhraseIsNull) {

    struct MyString object;
    init_string(&object);

    del_string(&object);

    cr_assert_eq(object.phrase, NULL, "Expected NULL, got %d", object.phrase);

}

Test(FreeAString, ErrorNone) {

    struct MyString object;
    init_string(&object);

    del_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);

}

Test(FreeAString, AgainMakesAnError) {

    struct MyString object;
    init_string(&object);

    del_string(&object);

    del_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_PHRASE_ALREADY_RELEASED, "Expected an eror MYSTRING_PHRASE_ALREADY_RELEASED (2), got %d", object.id_error);

}