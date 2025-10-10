#include "smystring.h"
#include "bop_mystring.h"

int counter_string(char* buff) {
    
    int length = 0;
    
    while(1) {
        
        if(buff[length] == '\0') break;
        length++;
    
    }

    return length;

};