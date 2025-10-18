/**
 * Example 09 - Getting an id error.
 * Demonstrates how to get an id error.
 *
 * To compile:
 * gcc example/example09_getting_id_error.c -Iinclude -Lbuild -lmystring -o example/example09
 */


#include <stdio.h>
#include "mystring.h"


int main () {

    /** 
     * The Struct of String, if you want you can use the typedef to remove keyword "struct"
     * 
     * Initializing two MyString objects
     */
    struct MyString example;


    // Initializing a String with a phrase "C is the best language"
    initwp_string(&example, "C is the best language"); 

    if(gete_string(example)) {

        enum ErrorMyString e = gete_string(example);

        printf("Initialization failed with id error [%d]\n", e);

    }


    // Free the String
    del_string(&example);

    if(gete_string(example)) {

        enum ErrorMyString e = gete_string(example);

        printf("Deletation failed with id error [%d]\n", e);

    }


    printf("\n==> Everything worked perfectly. Goodbye! <==\n");

    return 0;
}