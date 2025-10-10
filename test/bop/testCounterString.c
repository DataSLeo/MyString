#include <stdio.h>
#include <criterion/criterion.h>

#include "mystring.h"

/* 
SCENARIES:

1. The length of char* is zero 
2. The length of char* is variable

3. The char* buff is not initializated 
    PS: There is a problem in this scenario, because when char* buff is not initialized with a value it generates an 
    unexpected value that there is not way to handle. 

4. The String is NULL

*/


void testCounterStringIsZero();
void testCounterStringIsVariable();
// void testCounterStringIsNotInitialized();
void testCounterStringIsNull();


int main() {

    testCounterStringIsZero();
    printf("testCounterStringIsZero passed\n");

    testCounterStringIsVariable();
    printf("testCounterStringIsZero passed\n");

    // testCounterStringIsNotInitialized();
    // printf("testCounterStringIsNotInitialized passed\n");

    testCounterStringIsNull();
    printf("testCounterStringIsNull passed\n");

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

// void testCounterStringIsNotInitialized() {
//     char* buff;
//     int size;

//     size = counter_string(buff);

//     cr_assert_eq(size, 0);

//     return;
// }

void testCounterStringIsNull() {
    char *buff = NULL;
    int size;

    size = counter_string(buff);

    cr_assert_eq(size, 0);

    return;

}

