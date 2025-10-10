#include "smystring.h"
#include <stdlib.h>

void init_string(struct MyString *object_string) {
    
    // Allocing one Byte '\0'
    object_string->phrase = (char*) calloc(1, sizeof(char));
    object_string->size = 0;

    object_string->id_error = NONE;

    if(object_string->phrase == NULL) object_string->id_error = PHRASE_NOT_INITIALIZATED;

}

