#ifndef __SMYSTRING_H__
#define __SMYSTRING_H__

/* 
CREATED: 2025-10-09
CREATED BY: LEONARDO ALVES
NAME: (Struct) for My String

BRIEF: This header has the objective to create the basic struct to works my string.
*/


/* 
@brief Enum of Errors for My String. 
*/
enum ErrorMyString {
    /*There is no error.*/
    MYSTRING_NONE = 0,

    /*The String cannot be initialized.*/
    MYSTRING_PHRASE_NOT_INITIALIZATED,

    /*Trying to clear an already cleared String.*/
    MYSTRING_STRING_ALREADY_FREE
};


struct MyString {
    char* phrase;
    int size;
    enum ErrorMyString id_error;
};


/*
@brief initialize the struct MyString.

@param *object_string is the struct MyString.

@return enum ErrorMyString.

Expected error: MYSTRING_PHRASE_NOT_INITIALIZATED (1).
*/
enum ErrorMyString init_string(struct MyString *object_string); 


/*
@brief to free memory for struct MyString

@param *object_string is the struct MyString.

@return enum ErrorMyString.

Expected error: MYSTRING_STRING_ALREADY_FREE (2).
*/
enum ErrorMyString del_string(struct MyString *object_string);

#endif