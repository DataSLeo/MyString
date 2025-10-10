#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/* 
Cenaries:

1. The length of string is zero
2. The length of string is variable

*/


void testCounterStringIsZero();
void testCounterStringIsVariable();


int main() {

    printf("Testing: CounterStringIsZero...");
    testCounterStringIsZero();
    printf(" PASSED\n");

    printf("Testing: CounterStringIsVariable...");
    testCounterStringIsVariable();
    printf(" PASSED\n");

    return 0;
}


void testCounterStringIsZero() {
    char *buff = (char*) "";
    int size;

    size = counter_string(buff);

    cr_assert_eq(size, 0);

    return;

}

void testCounterStringIsVariable() {
    char *buff = (char*) "Leonardo";
    int size;

    size = counter_string(buff);

    cr_assert_eq(size, 8);

    return;
}


