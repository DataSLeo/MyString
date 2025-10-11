#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/*
SCENARIOS

1. The sum between the length of MyString object empty and the phrase empty need to be Zero.
2. If occurs all okay, return MYSTRING_NONE
3. Had the sum between the length of MyString object and the phrase.
4. The concat between MyString object and the phase need to be new MyString object with phrase.
5. The return need be MYSTRING_NONE (0)
6. The last character must be null terminated
7. Multiple Concats
*/


Test(ConcatString, SumLengthBetweenMyStringAndPhraseAllEmptyNeedToBeZero) {

    struct MyString object;
    init_string(&object);

    concat_string(&object, (char*)"");

    cr_assert_eq(object.length, 0, "Expected length 0, got %d", object.length);   

    del_string(&object);

}


Test(ConcatString, IdErrorIsNone) {

    struct MyString object;
    init_string(&object);

    concat_string(&object, (char*)"Apple tree");

    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected 0, got %d", object.id_error);   

    del_string(&object);

}


Test(ConcatString, HadSumBetweenLengthMyStringAndPhrase){

    struct MyString object;
    initwp_string(&object, (char*)"Minas");

    concat_string(&object, (char*)"Gerais");

    cr_assert_eq(object.length, 11, "Expected length 11, got %d", object.length);

    del_string(&object);

}


Test(ConcatString, MakeNewPhraseInMyStringByConcat) {

    struct MyString object;
    initwp_string(&object, (char*)"Bed");

    concat_string(&object, (char*)"room");

    struct MyString result_expected;
    initwp_string(&result_expected, (char*)"Bedroom");

    int is_equal = equals_string(object, result_expected);

    cr_assert_eq(1, is_equal, "Expected \"Bedroom\", got \"%s\"", object.phrase);

    del_string(&object);
    del_string(&result_expected);

}


Test(ConcatString, ReturnIsNone) {

    struct MyString object;
    initwp_string(&object, (char*)"Sam");

    enum ErrorMyString e = concat_string(&object, (char*)"Smith");

    cr_assert_eq(e, MYSTRING_NONE, "Expected 0, got %d", e);

    del_string(&object);

}


Test(ConcatString, LastCharacterNeedToBeNullTerminated) {

    struct MyString object;
    initwp_string(&object, (char*)"Sam");

    concat_string(&object, (char*)"Smith");

    int result_length = object.length;

    cr_assert_eq(object.phrase[result_length], '\0', "Expected '\\0', got %c", object.phrase[result_length]);

    del_string(&object);

}


Test(ConcatString, MultipleConcatsInitializedWithNoPhrase) {

    struct MyString object;
    init_string(&object);

    concat_string(&object, (char*)"C");
    concat_string(&object, (char*)"is");
    concat_string(&object, (char*)"the");
    concat_string(&object, (char*)"best");
    concat_string(&object, (char*)"language");
    concat_string(&object, (char*)"ever");

    cr_assert_eq(object.length, 22, "Expected length 22, got %d", object.length);
    
    struct MyString expected_phrase;
    initwp_string(&expected_phrase, (char*)"Cisthebestlanguageever");

    int is_equal = equals_string(object, expected_phrase);

    cr_assert_eq(1, is_equal, "Expected \"%s\", got \"%s\"", expected_phrase.phrase, object.phrase);

    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected 0, got %d", object.id_error);   

    int result_length = object.length;

    cr_assert_eq(object.phrase[result_length], '\0', "Expected '\\0', got %c", object.phrase[result_length]);

    del_string(&object);
    del_string(&expected_phrase);

}