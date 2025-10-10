#include "smystring.h"
#include "bop_mystring.h"
#include <stdlib.h>

int counter_string(char* buff) {

    int length = 0;

    if(buff == NULL) return length;

    while(1) {
        
        if(buff[length] == '\0') break;
        length++;
    
    }

    return length;

}

enum ErrorMyString initwp_string(struct MyString *object_string, char* phrase) {

    int size_phrase = counter_string(phrase);

    object_string->phrase = (char*) calloc(size_phrase + 1, sizeof(char));

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZATED;
        return MYSTRING_PHRASE_NOT_INITIALIZATED;
    }

    for(int i = 0; i < size_phrase; i++) {
        object_string->phrase[i] = phrase[i];
    }

    object_string->phrase[size_phrase] = '\0';
    object_string->size = size_phrase;
    object_string->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
    
}

int equals_string(struct MyString object_string1, struct MyString object_string2) {
    
    int size_os1 = object_string1.size;
    int size_os2 = object_string2.size;

    if(size_os1 != size_os2) return 0;

    for(int i = 0; i < size_os1; i++) {
        if(object_string1.phrase[i] != object_string2.phrase[i]) return 0; 
    }

    return 1;

}