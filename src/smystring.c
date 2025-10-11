#include "smystring.h"
#include <stdlib.h>
#include <stdio.h>

enum ErrorMyString init_string(struct MyString *object_string) {

    // Allocing one Byte '\0'
    object_string->phrase = (char*) calloc(1, sizeof(char));
    object_string->size = 0;

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZATED;
        return MYSTRING_PHRASE_NOT_INITIALIZATED;
    }

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;

}


enum ErrorMyString del_string(struct MyString *object_string) {

    if(object_string->phrase != NULL) {

        free(object_string->phrase);
        object_string->phrase = NULL;
        
        object_string->size = 0;

        object_string->id_error = MYSTRING_NONE;

        return MYSTRING_NONE;

    }

    object_string->id_error = MYSTRING_STRING_ALREADY_FREE;
    return MYSTRING_STRING_ALREADY_FREE;

}