#include "smystring.h"
#include <stdlib.h>
#include <stdio.h>

enum ErrorMyString init_string(struct MyString *object_string) {

    // Allocing one Byte '\0'
    object_string->phrase = (char*) calloc(1, sizeof(char));
    object_string->length = 0;

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
    }

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;

}


enum ErrorMyString del_string(struct MyString *object_string) {

    if(object_string->phrase != NULL) {

        free(object_string->phrase);
        object_string->phrase = NULL;
        
        object_string->length = 0;

        object_string->id_error = MYSTRING_NONE;

        return MYSTRING_NONE;

    }

    object_string->id_error = MYSTRING_PHRASE_ALREADY_RELEASED;
    return MYSTRING_PHRASE_ALREADY_RELEASED;

}