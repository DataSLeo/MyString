#ifndef __SMYSTRING_H__
#define __SMYSTRING_H__


enum ErrorMyString {
    MYSTRING_NONE = 0,
    MYSTRING_PHRASE_NOT_INITIALIZATED = 1
};


struct MyString {
    char* phrase;
    int size;
    enum ErrorMyString id_error;
};


// Function to initialize a String. It's should called always when starts works with String.
void init_string(struct MyString *object_string); 

// Function to delete a String.
void del_string(struct MyString *object_string);

#endif