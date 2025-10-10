// A simple example to how initiate a string and delete it.

#include <stdio.h>
#include "mystring.h"


int main () {
 
    // The Struct of String, if you want you can use the typedef to remove keyword "struct"
    struct MyString str;


    // Initializing a String by address memory
    if(init_string(&str) != MYSTRING_NONE) printf("Occurs an error by id [%d]\n", str.id_error);


    // Free the String by address memory
    if(del_string(&str) != MYSTRING_NONE) printf("Occurs an error by id [%d]\n", str.id_error);

    
    printf("It's works perfect. Bye world!\n");

    return 0;
}


// And that's it. Bye