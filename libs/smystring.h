#ifndef __SMYSTRING_H__
#define __SMYSTRING_H__


struct MyString {
    char* phrase;
    int size;

    int id_error;
};


// Function to initialize a String. It's should called always when starts works with String.
void init_string(struct MyString *object_string); 



#include "smystring.c"

#endif