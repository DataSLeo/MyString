#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. When assign a new value in a String, the length must be the new String
2. When assign a new value in a String, the last character must be \0
3. When assign a new value in a String, the content need to be equal new String
4. When assign a new value in a String, it's return need to be MYSTRING_NONE
*/


void testAssignStringHasASizeOfAnotherString();
void testAssignStringLastCharacterIsBackSlashZero();
void testAssignStringNeedToBeEqualAnotherString();
void testAssignStringReturnedNone();


int main() {

    testAssignStringHasASizeOfAnotherString();
    printf("testAssignStringHasASizeOfAnotherString passed\n");

    testAssignStringLastCharacterIsBackSlashZero();
    printf("testAssignStringLastCharacterIsBackSlashZero passed\n");

    testAssignStringNeedToBeEqualAnotherString();
    printf("testAssignStringNeedToBeEqualAnotherString passed\n");

    testAssignStringReturnedNone();
    printf("testAssignStringReturnedNone passed\n");

    return 0;
}

void testAssignStringHasASizeOfAnotherString() {

    struct MyString origin;
    struct MyString new_string;

    initwp_string(&origin, (char*)"");
    initwp_string(&new_string, (char*)"hello, world!");    

    assign_string(&origin, new_string.phrase);

    cr_assert(origin.size == 13);

    return;
}

void testAssignStringLastCharacterIsBackSlashZero() {

    struct MyString origin;
    struct MyString new_string;

    initwp_string(&origin, (char*)"Kent Beck");
    initwp_string(&new_string, (char*)"Bill Clinton");    

    assign_string(&origin, new_string.phrase);

    cr_assert(origin.phrase[13] == '\0');

    return;
}

void testAssignStringNeedToBeEqualAnotherString() {

    struct MyString origin;
    struct MyString new_string;

    initwp_string(&origin, (char*)"Linus Torvalds");
    initwp_string(&new_string, (char*)"Linux Debian");  
    
    assign_string(&origin, new_string.phrase);

    cr_assert(equals_string(origin, new_string) == 1);

    return;
}

void testAssignStringReturnedNone() {

    struct MyString origin;
    struct MyString new_string;

    initwp_string(&origin, (char*)"Spider Man");
    initwp_string(&new_string, (char*)"Wolverine");  

    assign_string(&origin, new_string.phrase);

    cr_assert(origin.id_error == MYSTRING_NONE);

    return;
}
