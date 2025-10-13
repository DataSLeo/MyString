#include <criterion/criterion.h>
#include "mystring.h"

/**
 * SCENARIOS:
 * 
 * 1. When assign a new value in a String, the length must be the new String
 * 2. When assign a new value in a String, the last character must be \0
 * 3. When assign a new value in a String, the content need to be equal new String
 * 4. When assign a new value in a String, it's return need to be MYSTRING_NONE
 */


Test(AssignString, HasASizeOfAnotherString) {

    struct MyString main_object;
    struct MyString new_object;

    initwp_string(&main_object, (char*)"");
    initwp_string(&new_object, (char*)"hello, world!");    

    assign_string(&main_object, new_object.phrase);

    cr_assert_eq(main_object.length, 13, "Expected 13, got %d", main_object.length);

    del_string(&main_object);
    del_string(&new_object);

}


Test(AssignString, LastCharacterIsBackSlashZero) {

    struct MyString main_object;
    struct MyString new_object;

    initwp_string(&main_object, (char*)"Kent Beck");
    initwp_string(&new_object, (char*)"Bill Clinton");    

    assign_string(&main_object, new_object.phrase);

    cr_assert_eq(main_object.phrase[13], '\0', "Expected Null Terminator (\'\0\'), got %c", main_object.phrase[13]);

    del_string(&main_object);
    del_string(&new_object);

}

Test(AssignString, NeedToBeEqualAnotherString) {

    struct MyString main_object;
    struct MyString new_object;

    initwp_string(&main_object, (char*)"Linus Torvalds");
    initwp_string(&new_object, (char*)"Linux Debian");  
    
    assign_string(&main_object, new_object.phrase);

    int result = equals_string(main_object, new_object);

    cr_assert_eq(result, 1, "Expected true (1), got false (%d)", result);

    del_string(&main_object);
    del_string(&new_object);

}

Test(AssignString, ReturnedNone) {

    struct MyString main_object;
    struct MyString new_object;

    initwp_string(&main_object, (char*)"Spider Man");
    initwp_string(&new_object, (char*)"Wolverine");  

    assign_string(&main_object, new_object.phrase);

    cr_assert_eq(main_object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", main_object.id_error);

    del_string(&main_object);
    del_string(&new_object);

}