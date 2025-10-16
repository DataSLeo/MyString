#include <criterion/criterion.h>
#include "mystring.h"

/**
 * SCENARIOS:
 * 
 * 1. With no error, return MYSTRING_NONE (0).
 * 2. With no error, id_error is setted MYSTRING_NONE (0).
 * 3. If there are no spaces at the beginning, the length value should be the same as the original.
 * 4. If the sentence has no spaces at the beginning, it should be returned as in the original.
 * 5. The last character must be null terminator '\0'.
 * 6. The returned phrase cannot be NULL.
 * 7. If there are spaces at the beginning, the length value should be less than the original.
 * 8. If the sentence has a space at the beginning, it should be returned without spaces at the beginning.
 * 9. If the beginning has '\n', the returned Phrase must not have it.
 * 10. If the beginning has '\t', the returned Phrase must not have it.
 * 11. If the beginning has '\r', the returned Phrase must not have it.
 * 12. If the MyString object used as an argument is NULL, an error will be thrown.
 * 13. If the Phrase of the MyString object is NULL, an error is thrown.
 */


Test(TestLStripString, ReturnMYSTRINGNONE) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    enum ErrorMyString e = lstrip_string(&object);

    cr_assert_eq(e, MYSTRING_NONE, "Expected error MYSTRING_NONE (0), got %d", e);

    del_string(&object);

}

Test(TestLStripString, IdErrorIsMYSTRINGNONE) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    lstrip_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error MYSTRING_NONE (0), got %d", object.id_error);

    del_string(&object);

}

Test(TestLStripString, NoSpaceAtBegginingReturnOriginalLength) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    int original_length = object.length;

    lstrip_string(&object);

    int after_length = object.length;

    cr_assert_eq(after_length, original_length, "Expected length %d, got %d", original_length, after_length);

    del_string(&object); 

}

Test(TestLStripString, NoSpaceAtBegginingReturnOriginalPhrase) {

    struct MyString object;
    struct MyString copy;

    initwp_string(&object, "hello, world!");
    initwp_string(&copy, object.phrase);


    lstrip_string(&object);

    int is_equal = equals_string(object, copy);


    cr_assert_eq(is_equal, 1, "Expected equal MyString phrase (1), got %d", is_equal);

    del_string(&object);
    del_string(&copy);

}

Test(TestLStripString, LastCharacterMustBeNullTerminator) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    lstrip_string(&object);

    cr_assert_eq(object.phrase[object.length], '\0', "Expected null terminator (\'\\0\'), got %c", object.phrase[object.length]);

    del_string(&object);
    
}

Test(TestLStripString, PhraseReturnedCannotBeNull) {

    struct MyString object;
    initwp_string(&object, "hello, world!");

    lstrip_string(&object);

    cr_assert(object.phrase != NULL, "Expected \"hello, world!\", got %d", NULL);

    del_string(&object);
        
}

Test(TestLStripString, HasSpacesAndReturnedLowerThanOriginalLength) {

    struct MyString object;
    initwp_string(&object, "  hello, world!");

    int defined_spaces_at_beggin = 2;
    int original_length = object.length;

    int new_length = original_length - defined_spaces_at_beggin;

    lstrip_string(&object);

    cr_assert_eq(object.length, new_length, "Expected length %d, got %d", new_length, object.length);

    del_string(&object);    

}

Test(TestLStripString, HasSpacesAndReturnedNewPhraseWithoutSpaceAtBeggining) {

    struct MyString object;
    struct MyString expected_phrase;


    initwp_string(&object, "  hello, world!");
    initwp_string(&expected_phrase, "hello, world!");


    enum ErrorMyString e = lstrip_string(&object);

    int is_equal = equals_string(object, expected_phrase);


    cr_assert_eq(is_equal, 1, "Expected \"%s\", got %s", expected_phrase.phrase, object.phrase);
    cr_assert_eq(object.phrase[object.length], '\0', "Expected null terminator (\'\\0\'), got %c", object.phrase[object.length]);
    cr_assert(object.phrase != NULL, "Expected \"hello, world!\", got %d", NULL);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected error MYSTRING_NONE (0), got %d", e);


    del_string(&object);    
    del_string(&expected_phrase);

}

Test(TestLStripString, HasBackSlashNAtBegginingAndReturnedShouldNotHave) {


    struct MyString object;
    struct MyString expected_phrase;


    initwp_string(&object, "\nhello, world!");
    initwp_string(&expected_phrase, "hello, world!");


    enum ErrorMyString e = lstrip_string(&object);

    int is_equal = equals_string(object, expected_phrase);


    cr_assert_eq(is_equal, 1, "Expected \"%s\", got %s", expected_phrase.phrase, object.phrase);
    cr_assert_eq(object.phrase[object.length], '\0', "Expected null terminator (\'\\0\'), got %c", object.phrase[object.length]);
    cr_assert(object.phrase != NULL, "Expected \"hello, world!\", got %d", NULL);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected error MYSTRING_NONE (0), got %d", e);


    del_string(&object);    
    del_string(&expected_phrase);

}

Test(TestLStripString, HasBackSlashTAtBegginingAndReturnedShouldNotHave) {


    struct MyString object;
    struct MyString expected_phrase;


    initwp_string(&object, "\thello, world!");
    initwp_string(&expected_phrase, "hello, world!");


    enum ErrorMyString e = lstrip_string(&object);

    int is_equal = equals_string(object, expected_phrase);


    cr_assert_eq(is_equal, 1, "Expected \"%s\", got %s", expected_phrase.phrase, object.phrase);
    cr_assert_eq(object.phrase[object.length], '\0', "Expected null terminator (\'\\0\'), got %c", object.phrase[object.length]);
    cr_assert(object.phrase != NULL, "Expected \"hello, world!\", got %d", NULL);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected error MYSTRING_NONE (0), got %d", e);


    del_string(&object);    
    del_string(&expected_phrase);

}

Test(TestLStripString, HasBackSlashRAtBegginingAndReturnedShouldNotHave) {


    struct MyString object;
    struct MyString expected_phrase;


    initwp_string(&object, "\rhello, world!");
    initwp_string(&expected_phrase, "hello, world!");


    enum ErrorMyString e = lstrip_string(&object);

    int is_equal = equals_string(object, expected_phrase);


    cr_assert_eq(is_equal, 1, "Expected \"%s\", got %s", expected_phrase.phrase, object.phrase);
    cr_assert_eq(object.phrase[object.length], '\0', "Expected null terminator (\'\\0\'), got %c", object.phrase[object.length]);
    cr_assert(object.phrase != NULL, "Expected \"hello, world!\", got %d", NULL);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected error MYSTRING_NONE (0), got %d", e);


    del_string(&object);    
    del_string(&expected_phrase);

}

Test(TestLStripString, PhraseIsNULLAndMustReturnError) {

    struct MyString phrase_is_null;

    phrase_is_null.phrase = NULL;

    enum ErrorMyString e = lstrip_string(&phrase_is_null);

    cr_assert_eq(e, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected error MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", e);
    cr_assert_eq(phrase_is_null.id_error, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected id_error MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", phrase_is_null.id_error);

    del_string(&phrase_is_null);

}

Test(TestLStripString, MyStringIsNULLAndMustReturnError) {

    struct MyString object_is_null;

    enum ErrorMyString e = lstrip_string(&object_is_null);

    cr_assert_eq(e, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected error MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", e);
    cr_assert_eq(object_is_null.id_error, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected id_error MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", object_is_null.id_error);

    del_string(&object_is_null);

}