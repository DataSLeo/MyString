#include <criterion/criterion.h>
#include "mystring.h"

/**
 * SCENARIOS:
 * 
 * 1. Send an error and get same
 */


Test(TestGeteString, PhraseIsNULLAndMustReturnError) {

    struct MyString object;
    object.id_error = MYSTRING_PHRASE_ALREADY_RELEASED;

    enum ErrorMyString e = gete_string(object);

    cr_assert_eq(e, MYSTRING_PHRASE_ALREADY_RELEASED, "Expected returned errro MYSTRING_PHRASE_ALREADY_RELEASED (2), got %d", e);

    del_string(&object);

}