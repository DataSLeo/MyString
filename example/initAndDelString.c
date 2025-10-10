// A simple example to how initiate a string and delete it.

#include "../include/mystring.h"


int main () {
 
    // The Struct of String, if you want you can use the typedef to remove keyword "struct"
    struct MyString str;

    // Initializing a String by address memory
    init_string(&str);

    // Free the String by address memory
    del_string(&str);
    
    return 0;
}


// And that's it. Bye