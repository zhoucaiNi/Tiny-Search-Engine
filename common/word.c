/*
 *
 * word.c 
 *
 *
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


// normalizeString | converts a string into lower case 

void normalizeString(char* str){
  // for loop to turn every char of the string to lower case
    for(int i=0 ; i < strlen(str) ; i++){
      str[i] = tolower(str[i]);

    }


}
