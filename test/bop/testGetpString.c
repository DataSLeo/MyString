#include <criterion/criterion.h>
#include "mystring.h"

/**
 * SCENARIOS:
 * 
 * 1. Get phrase of MyString object
 * 2. If Phrase from MyString object is NULL, return an empty char*
 */


Test(TestGetpString, GetPhraseOfMyString) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    char *string = getp_string(object);

    struct MyString equal_object;
    initwp_string(&equal_object, string);

    int is_equal = equals_string(object, equal_object);

    cr_assert_eq(is_equal, 1, "Expected 1, got %d", is_equal);

    del_string(&object);
    del_string(&equal_object);

}

Test(TestGetpString, IfPhraseIsNotNULLReturnAnEmptyCharPointer) {

    struct MyString object;
    object.phrase = NULL;

    struct MyString expected_object;
    struct MyString receive_object;

    initwp_string(&expected_object, "");

    char *string = getp_string(object); 
    initwp_string(&receive_object, string);
    
    int is_equal = equals_string(expected_object, receive_object);

    cr_assert_eq(is_equal, 1, "Expected 1, got %d", is_equal);

    del_string(&object);
    del_string(&receive_object);
    del_string(&expected_object);

}