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
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
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
    
    // Mark id_error and length as undefined to ensure fresh execution
    origin->id_error = ID_ERROR_RESETED;
    origin->length = LENGTH_RESETED;
    

    int length_phrase = counter_string(phrase);
    
    origin->phrase = (char*) realloc((char*) origin->phrase, (length_phrase + 1) * sizeof(char));
    
    if(origin->phrase == NULL) {
        origin->id_error = MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
        return MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
    }

    for(int i = 0; i < length_phrase; i++) {
        origin->phrase[i] = phrase[i];
    }

    origin->phrase[length_phrase] = '\0';
    origin->length = length_phrase; 
    origin->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
}

enum ErrorMyString concat_string(struct MyString *object_string, char* phrase){    
    
    // Mark id_error and length as undefined to ensure fresh execution
    object_string->id_error = ID_ERROR_RESETED;
    int length_tmp = object_string->length;
    object_string->length = LENGTH_RESETED;


    int length_phrase = counter_string(phrase);

    int sum = length_phrase + length_tmp;
    
    object_string->phrase = (char*) realloc(object_string->phrase, (sum + 1) * sizeof(char));

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
        return MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
    }

    for(int i = 0; i < length_phrase; i++, length_tmp++) {
        object_string->phrase[length_tmp] = phrase[i];
    }

    object_string->phrase[sum] = '\0';
    object_string->length = sum;

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;
}

enum ErrorMyString remasp_string(struct MyString *object_string) {

    // Mark id_error and length as undefined to ensure fresh execution
    object_string->id_error = ID_ERROR_RESETED;
    int length_tmp = object_string->length;
    object_string->length = LENGTH_RESETED;    

    int how_many_spaces = 0; 

    for(int i = 0; i < length_tmp; i++) {
        if(object_string->phrase[i] == ' '){
            how_many_spaces++;
        }
    }


    int length_phrase_no_space = length_tmp - how_many_spaces;

    char buff[length_phrase_no_space];

    for(int i = 0, index_buff = 0; i < length_tmp; i++) {
        if(object_string->phrase[i] != ' ') {
            buff[index_buff] = object_string->phrase[i];
            index_buff++;
        }
    }

    // For more security 
    free(object_string->phrase);
    object_string->phrase = NULL;

    
    object_string->phrase = (char*) calloc(length_phrase_no_space + 1, sizeof(char));
    
    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
    }

    for(int i = 0; i < length_phrase_no_space; i++) {
        object_string->phrase[i] = buff[i];
    }

    object_string->phrase[length_phrase_no_space] = '\0';
    object_string->length = length_phrase_no_space;

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;
}
