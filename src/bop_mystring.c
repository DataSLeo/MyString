#include "smystring.h"
#include "bop_mystring.h"
#include <stdlib.h>

int counter_string(char *buff) {

    int length = 0;

    if(buff == NULL) return length;

    while(1) {
        
        if(buff[length] == '\0') break;
        length++;
    
    }

    return length;

}

enum ErrorMyString initwp_string(struct MyString *object_string, char *phrase) {

    int length_phrase = counter_string(phrase);

    object_string->phrase = (char*) calloc(length_phrase + 1, sizeof(char));

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZATED;
        return MYSTRING_PHRASE_NOT_INITIALIZATED;
    }

    for(int i = 0; i < length_phrase; i++) {
        object_string->phrase[i] = phrase[i];
    }

    object_string->phrase[length_phrase] = '\0';
    object_string->length = length_phrase;
    object_string->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
    
}

int equals_string(struct MyString object_string1, struct MyString object_string2) {
    
    int length_os1 = object_string1.length;
    int length_os2 = object_string2.length;

    if(length_os1 != length_os2) return 0;

    for(int i = 0; i < length_os1; i++) {
        if(object_string1.phrase[i] != object_string2.phrase[i]) return 0; 
    }

    return 1;

}

enum ErrorMyString assign_string(struct MyString *origin, char *phrase) {
    
    int length_phrase = counter_string(phrase);
    
    origin->phrase = (char*) realloc((char*) origin->phrase, (length_phrase + 1) * sizeof(char));
    
    if(origin->phrase == NULL) {
        origin->id_error = MYSTRING_PHRASE_NOT_INITIALIZATED;
        return MYSTRING_PHRASE_NOT_INITIALIZATED;
    }

    for(int i = 0; i < length_phrase; i++) {
        origin->phrase[i] = phrase[i];
    }

    origin->phrase[length_phrase] = '\0';
    origin->length = length_phrase; 
    origin->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
}