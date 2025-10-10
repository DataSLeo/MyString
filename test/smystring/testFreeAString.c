#include <stdio.h>
#include <criterion/criterion.h>

#include "../include/mystring.h"


void testFreeAStringSizeIsZero();
void testFreeAStringPhraseIsNull();
void testFreeAStringErrorNone();


int main () {
    testFreeAStringSizeIsZero();
    printf("testFreeAStringSizeIsZero passed\n");

    testFreeAStringPhraseIsNull();
    printf("testFreeAStringPhraseIsNull passed\n");

    testFreeAStringErrorNone();
    printf("testFreeAStringErrorNone passed\n");

    return 0;
}



void testFreeAStringSizeIsZero() {
    struct MyString string;
    init_string(&string);

    del_string(&string);

    cr_assert_eq(string.size, 0, "Error in size");

}

void testFreeAStringPhraseIsNull() {
    struct MyString string;
    init_string(&string);

    del_string(&string);

    cr_assert(string.phrase == NULL);

}

void testFreeAStringErrorNone() {
    struct MyString string;
    init_string(&string);

    del_string(&string);

    cr_assert(string.id_error == MYSTRING_NONE);

}