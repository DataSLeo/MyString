/**
 * Example 07 - Using lstrip_string to remove all leading spaces.
 * Demonstrates how to remove all leading spaces.
 *
 * To compile:
 * gcc example/example07_using_lstrip.c -Iinclude -Lbuild -lmystring -o example/example07
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


    // Initializing a String with a phrase "     C is the best language" (5 spaces at beggining)
    enum ErrorMyString e = initwp_string(&example, "     C is the best language"); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    // Printing the string (example) and the length
    printf("%s (%d)\n", example.phrase, example.length);


    // Removing the spaces
    e = lstrip_string(&example);

    if(e) {
        printf("Remove spaces failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }    


    // Printing the result string and the length
    printf("%s (%d)\n", example.phrase, example.length);


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