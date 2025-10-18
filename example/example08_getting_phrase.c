/**
 * Example 08 - Getting a string.
 * Demonstrates how to get a string.
 *
 * To compile:
 * gcc example/example08_getting_phrase.c -Iinclude -Lbuild -lmystring -o example/example08
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
    enum ErrorMyString e = initwp_string(&example, "C is the best language"); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    // Printing the string (example) and the length
    printf("%s (%d)\n", getp_string(example), example.length);

    
    // Free the String
    e = del_string(&example);

    if(e) {
        printf("Deletation failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }


    printf("\n==> Everything worked perfectly. Goodbye! <==\n");

    return 0;
}