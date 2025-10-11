#ifndef __BOP_MYSTRING_H__
#define __BOP_MYSTRING_H__

/* 
CREATED: 2025-10-10
CREATED BY: LEONARDO ALVES
NAME: (Basic Operations) for My String

BRIEF: This header has the objective to create basic operations for my string.
*/


/* 
@brief is an algorithm to finding the length of a String.
It's works until find the special character \0.

@param *buff it the String to be found the size.

@return the length of the String.
*/
int counter_string(char *buff);


/* 
@brief initialize string with a phrase.

@param object_string it's address of MyString.
@param phrase it's the phrase who will put in object_string. 

@return enum ErrorMyString.

Expected error: MYSTRING_PHRASE_NOT_INITIALIZATED.
*/
enum ErrorMyString initwp_string(struct MyString *object_string, char *phrase);


/* 
@brief verify if two strings differents are equals.

@param object_string1 first string.
@param object_string2 second string. 

@return 1 if are equals else 0.
*/
int equals_string(struct MyString object_string1, struct MyString object_string2);


/* 
@brief assign a new String.

@param origin origin String.
@param phrase new phrase. 

@return enum ErrorMyString

Expected error: MYSTRING_PHRASE_NOT_INITIALIZATED.
*/
enum ErrorMyString assign_string(struct MyString *origin, char *phrase);

#endif