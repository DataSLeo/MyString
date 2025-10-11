/**
 * Example 01 - Initialize and Delete a MyString
 * Demonstrates how to initialize a MyString object and free its memory.
 *
 * To compile:
 * gcc example/example01_initialize_and_delete_string.c -Iinclude -Lbuild -lmystring -o example/example01
 */


#include <stdio.h>
#include "mystring.h"


int main () {
 
    // The Struct of String, if you want you can use the typedef to remove keyword "struct"
    struct MyString example;

    // Initializing a String by address memory
    enum ErrorMyString e = init_string(&example); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }


    // Free the String by address memory
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