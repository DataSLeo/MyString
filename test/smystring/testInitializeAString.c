#include "stdio.h"
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. Initialize a String and Verify it's properties (size = 0, id_error = 0).
2. The phrase must to have null-terminator in.

*/


void testInitializeAStringNewString();
void testInitializeAStringNullTermintor();

int main () {
    testInitializeAStringNewString();
    printf("testInitializeAStringNewString passed\n");

    testInitializeAStringNullTermintor();
    printf("testInitializeAStringNullTermintor passed\n");

    return 0;
}


void testInitializeAStringNewString() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.length, 0);     
    cr_assert_eq(string.id_error, MYSTRING_NONE);

}

void testInitializeAStringNullTermintor() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.phrase[0], '\0');

}
