#include "stdio.h"
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. Initialize a String and Verify it's properties (size = 0, id_error = 0).
2. The phrase must to have null-terminator in.

*/


void testInitializeAStringNewString();
void testInitializeAStringNullTerminator();

int main () {
    testInitializeAStringNewString();
    printf("testInitializeAStringNewString passed\n");

    testInitializeAStringNullTerminator();
    printf("testInitializeAStringNullTerminator passed\n");

    return 0;
}


void testInitializeAStringNewString() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.length, 0);     
    cr_assert_eq(string.id_error, MYSTRING_NONE);

}

void testInitializeAStringNullTerminator() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.phrase[0], '\0');

}
