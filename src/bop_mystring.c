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

};