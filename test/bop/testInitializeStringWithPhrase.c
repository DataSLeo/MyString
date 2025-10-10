#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. Phrase is empty and has \0
2. String was filled correctly

*/


void testInitializeStringWithPhraseIsEmpty();
void testInitializeStringWithPhrase();


int main() {

    testInitializeStringWithPhraseIsEmpty();
    printf("testInitializeStringWithPhraseIsEmpty passed\n");

    testInitializeStringWithPhrase();
    printf("testInitializeStringWithPhrase passed\n");


    return 0;
}

void testInitializeStringWithPhraseIsEmpty() {

    struct MyString string;
    initwp_string(&string, (char*)"");

    cr_assert_eq(string.size, 0);
    cr_assert_eq(string.phrase[0], '\0');
    cr_assert_eq(string.id_error, MYSTRING_NONE);

    return;
}

void testInitializeStringWithPhrase() {

    struct MyString string;
    initwp_string(&string, (char*)"hello, world!");

    cr_assert_eq(string.size, 13);
    cr_assert_eq(string.id_error, MYSTRING_NONE);

}