#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. One of Strings compared has differents sizes
2. The Strings are equals
3. Two String has filled, but are differents

*/


void testEqualStringOneOfStringsHasDifferentsSizes();
void testEqualStringAllIsEquals();
void testEqualStringDifferentBetween();

int main() {

    testEqualStringOneOfStringsHasDifferentsSizes();
    printf("testEqualStringOneOfStringsHasDifferentsSizes passed\n");

    testEqualStringAllIsEquals();
    printf("testEqualStringAllIsEquals passed\n");

    testEqualStringDifferentBetween();
    printf("testEqualStringDifferentBetween passed\n");

    return 0;
}

void testEqualStringOneOfStringsHasDifferentsSizes() {

    struct MyString string1;
    initwp_string(&string1, (char*)"Kent Beck");

    struct MyString string2;
    initwp_string(&string2, (char*)"Linux Torvalds");

    int result = equals_string(string1, string2);

    cr_assert_eq(0, result);

    return;
}

void testEqualStringAllIsEquals() {

    struct MyString string1;
    initwp_string(&string1, (char*)"C is best");
    
    struct MyString string2;
    initwp_string(&string2, (char*)"C is best");

    int result = equals_string(string1, string2);

    cr_assert_eq(1, result);

}

void testEqualStringDifferentBetween() {

    struct MyString string1;
    initwp_string(&string1, (char*)"Coffee");

    struct MyString string2;
    initwp_string(&string2, (char*)"Milk");

    int result = equals_string(string1, string2);

    cr_assert_eq(0, result);

} 