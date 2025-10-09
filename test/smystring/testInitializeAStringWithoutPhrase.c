#include "stdio.h"
#include "../../libs/smystring.h"
#include <criterion/criterion.h>


void testInitializeAStringWithoutPhrase();


int main () {

    testInitializeAStringWithoutPhrase();

    return 0;
}



void testInitializeAStringWithoutPhrase() {
    
    struct MyString string;
    init_string(&string);

    cr_assert_eq(string.size, 0, "Size of string is diferent to Zero");     
    cr_assert_eq(string.id_error, 0, "The id error is not Zero (normal)");

}