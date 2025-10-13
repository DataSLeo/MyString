#include <criterion/criterion.h>
#include "mystring.h"

/* 
 * SCENARIOS:
 *
 * 1. One of Strings compared has differents sizes
 * 2. The Strings are equals
 * 3. Two String has filled, but are differents
 */


Test(TestEqualString, OneOfStringsHasDifferentsSizes) {

    struct MyString object1;
    struct MyString object2;

    initwp_string(&object1, (char*)"Kent Beck");
    initwp_string(&object2, (char*)"Linus Torvalds");

    int result = equals_string(object1, object2);

    cr_assert_eq(result, 0, "Expected false (0), got true (%d)", result);

    del_string(&object1);
    del_string(&object2);

}

Test(TestEqualString, AllIsEquals) {

    struct MyString object1;
    struct MyString object2;

    initwp_string(&object1, (char*)"C is best");
    initwp_string(&object2, (char*)"C is best");

    int result = equals_string(object1, object2);

    cr_assert_eq(result, 1, "Expected true (1), got false (%d)", result);

    del_string(&object1);
    del_string(&object2);

}

Test(TestEqualString, DifferentBetween) {

    struct MyString object1;
    struct MyString object2;

    initwp_string(&object1, (char*)"Coffee");    
    initwp_string(&object2, (char*)"Milk");

    int result = equals_string(object1, object2);

    cr_assert_eq(result, 0, "Expected 0, got %d", result);

    del_string(&object1);
    del_string(&object2);

}