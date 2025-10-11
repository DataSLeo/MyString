/**
 * Example 03 - Checking the length in MyString object.
 * Demonstrates how to see the length.
 *
 * To compile:
 * gcc example/example03_checking_the_length.c -Iinclude -Lbuild -lmystring -o example/example03
 */


#include <stdio.h>
#include "mystring.h"


int main () {
 
    // The Struct of String, if you want you can use the typedef to remove keyword "struct"
    struct MyString example;

    // Initializing a String with a phrase "PacMan"
    enum ErrorMyString e = initwp_string(&example, "PacMan"); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    // Printing the phrase
    printf("%s\n", example.phrase);

    
    // Getting the length and printing it
    int length = example.length;
    printf("The length of MyString object is: %d\n", length);
    

    // Free the String
    e = del_string(&example);

    if(e) {
        printf("Deletation failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }
    

    printf("Everything worked perfectly. Goodbye!\n");

    return 0;
}