/**
 * Example 05 - Checking if two MyString objects phrase are equals.
 * Demonstrates how to check if two phrases are equals or not.
 *
 * To compile:
 * gcc example/example05_is_equal.c -Iinclude -Lbuild -lmystring -o example/example05
 */


#include <stdio.h>
#include "mystring.h"


int main () {
 
    /** 
     * The Struct of String, if you want you can use the typedef to remove keyword "struct"
     * 
     * Initializing two MyString objects
     */
    struct MyString example1;
    struct MyString example2;


    // Initializing a String with a phrase "VSCode"
    enum ErrorMyString e = initwp_string(&example1, "VSCode"); 

    if(e) {
        printf("Initialization failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    e = initwp_string(&example2, "VSCode");

    int result = equals_string(example1, example2);

    
    if(result) {

        printf("\"%s\" and \"%s\" are equals\n", example1.phrase, example2.phrase);
        
    } else {

        printf("\"%s\" and \"%s\" are not equals\n", example1.phrase, example2.phrase);

    }


    // Assigning a new phrase 
    e = assign_string(&example2, "Sumblime Text");

    if(e) {
        printf("Assigning failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }


    result = equals_string(example1, example2);


    if(result) {

        printf("\"%s\" and \"%s\" are equals\n", example1.phrase, example2.phrase);
        
    } else {

        printf("\"%s\" and \"%s\" are not equals\n", example1.phrase, example2.phrase);

    }
    

    // Free the String
    e = del_string(&example1);

    if(e) {
        printf("Deletation failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }

    e = del_string(&example2);

    if(e) {
        printf("Deletation failed with id error [%d]\n", e);

        /**
         * You can get erro too using the property id_error from yout MyString object. 
         */

    }
    

    printf("Everything worked perfectly. Goodbye!\n");

    return 0;
}