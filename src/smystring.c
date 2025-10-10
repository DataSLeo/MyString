#include "smystring.h"
#include <stdlib.h>

void init_string(struct MyString *object_string) {
    
    // Allocing one Byte '\0'
    object_string->phrase = (char*) calloc(1, sizeof(char));
    object_string->size = 0;

    object_string->id_error = MYSTRING_NONE;

    if(object_string->phrase == NULL) object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZATED;

}

void del_string(struct MyString *object_string) {

    if(object_string->phrase != NULL) {

        free(object_string->phrase);
        object_string->phrase = NULL;

    }

    object_string->size = 0;
    object_string->id_error = MYSTRING_NONE;

}