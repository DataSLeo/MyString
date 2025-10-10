#include "stdio.h"
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. Initialize a String and Verify it's properties (size = 0, id_error = 0).
2. Initialize a String initialized.

*/


void testInitializeAStringNewString();
void testInitializeAStringAlreadyInitialized();


int main () {
    testInitializeAStringNewString();
    printf("testInitializeAStringNewString passed\n");

    testInitializeAStringAlreadyInitialized();
    printf("testInitializeAStringAlreadyInitialized passed\n");

    return 0;
}


void testInitializeAStringNewString() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.size, 0);     
    cr_assert_eq(string.id_error, MYSTRING_NONE);

}

void testInitializeAStringAlreadyInitialized() {

    struct MyString string;
    init_string(&string);

    init_string(&string);

    cr_assert_eq(string.id_error, MYSTRING_STRING_ALREADY_INITIALIZED);

}