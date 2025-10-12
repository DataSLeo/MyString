#include <criterion/criterion.h>
#include "mystring.h"


/**
 * SCENARIOS
 * 
 * 1. The return needs to be MYSTRING_NONE (0)
 * 2. If occurs all okay, the property id_error needs to be MYSTRING_NONE (0)
 * 3. The result of the String that has space must not have any more
 * 4. The last character must be null terminated '\0' 
 * 5. The length of the new string must be equal to the previous one but without spaces
 * 6. If the string is initialized by init_string it should work normally (length = 0, id_error = MYSTRING_NONE, phrase = '\0', return error = MYSTRING_NONE) 
 */


Test(RemoveAllSpacesString, ErroReturnedIsNone) {

    struct MyString object;
    initwp_string(&object, "C is a language");


    enum ErrorMyString e = remasp_string(&object);

    cr_assert_eq(e, MYSTRING_NONE, "Expected error %d, got %d", MYSTRING_NONE, e);

    del_string(&object);

}

Test(RemoveAllSpacesString, IdErroFromMyStringIsNone) {

    struct MyString object;
    initwp_string(&object, "C is a language");


    remasp_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error %d, got %d", MYSTRING_NONE, object.id_error);

    del_string(&object);

}

Test(RemoveAllSpacesString, PhraseOfMyStringMustBeWithNoSpaces) {

    struct MyString object;
    initwp_string(&object, "C is a language");


    remasp_string(&object);

    struct MyString expected_phrase;
    initwp_string(&expected_phrase, "Cisalanguage");

    int is_equal = equals_string(object, expected_phrase);

    cr_assert_eq(is_equal, 1, "Expected %d (equals), got %d", 1, is_equal);

    del_string(&object);
    del_string(&expected_phrase);

}

Test(RemoveAllSpacesString, LastCharacterNeedToBeNullTerminated){

    struct MyString object;
    initwp_string(&object, "C is a language");


    remasp_string(&object);

    int length_of_object = object.length;

    cr_assert_eq(object.phrase[length_of_object], '\0', "Expected '\\0', got %d", object.phrase[length_of_object]);

    del_string(&object);

}

Test(RemoveAllSpacesString, PhraseOfMyStringNeedsToBeDiffThanWithInSpaces){

    struct MyString object;
    initwp_string(&object, "C is a language");
    
    
    int length_with_spaces = object.length;

    remasp_string(&object);

    int length_with_no_spaces = object.length;


    cr_assert_eq(length_with_no_spaces, 12, "Expected length is 12, got %d", length_with_no_spaces);

    del_string(&object);

}

Test(RemoveAllSpacesString, PhraseInitializedByInitStringMustBeWorkNormally){
 
    struct MyString object;
    init_string(&object);
    
    enum ErrorMyString e = remasp_string(&object);


    cr_assert_eq(object.phrase[0], '\0', "Expected '\\0', got %d", object.phrase[0]);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected id_error %d, got %d", MYSTRING_NONE, object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected error %d, got %d", MYSTRING_NONE, e);
    cr_assert_eq(object.length, 0, "Expected length is 0, got %d", object.length);    

    del_string(&object);

}