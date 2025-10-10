#ifndef __SMYSTRING_H__
#define __SMYSTRING_H__


/* 
CREATED: 2025-10-09
CREATED BY: LEONARDO ALVES
NAME: (Struct) for My String

BRIEF: This header has the objective to create the basic struct to works my string.
*/


enum ErrorMyString {
    MYSTRING_NONE = 0,
    MYSTRING_PHRASE_NOT_INITIALIZATED = 1
};


struct MyString {
    char* phrase;
    int size;
    enum ErrorMyString id_error;
};


/*
@brief initialize the struct MyString.

@param *object_string is the struct MyString.

@return void.
*/
void init_string(struct MyString *object_string); 


/*
@brief to free memory for struct MyString

@param *object_string is the struct MyString.

@return void.
*/
void del_string(struct MyString *object_string);

#endif