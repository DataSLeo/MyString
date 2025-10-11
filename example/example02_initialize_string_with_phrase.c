/**
 * Example 02 - Initialize a MyString object with a phase
 * Demonstrates how to initialize a MyString object with phrase.
 *
 * To compile:
 * gcc example/example02_initialize_string_with_phrase.c -Iinclude -Lbuild -lmystring -o example/example02
 */


#include <stdio.h>
#include "mystring.h"


int main () {
 
    // The Struct of String, if you want you can use the typedef to remove keyword "struct"
    struct MyString example;

    // Initializing a String with a phrase "Hello, world!"
    enum ErrorMyString e = initwp_string(&example, "Hello, world!"); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    // Printing the phrase
    printf("%s\n", example.phrase);


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