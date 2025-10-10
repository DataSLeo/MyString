#include "stdio.h"
#include <criterion/criterion.h>

#include "../include/mystring.h"


void testInitializeAString();


int main () {
    testInitializeAString();
    printf("testInitializeAString passed\n");

    return 0;
}



void testInitializeAString() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.size, 0);     
    cr_assert_eq(string.id_error, MYSTRING_NONE);

}