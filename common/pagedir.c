/*
 *
 * pagedir.c 
 *
 * Zhoucai Ni, CS50 Lab 4
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "webpage.h"
#include "file.h"

/******  pagedir_init ******/
// see pegedir.h for for info

bool pagedir_validate(const char* pageDirectory){
  // construct the pathname for the .crawler file in that directory 
  // pagDirectory eg. = 
  if(pageDirectory == NULL){
    return false;
  }
  FILE *fp;

  char* pathName = malloc( sizeof(char) * (strlen(pageDirectory) + strlen("/.crawler") ) + 1 ); 

  sprintf(pathName, "%s/.crawler", pageDirectory); 
  // open the file for reading; on error -> return false
  if( ( fp = fopen(pathName, "r") ) == NULL){
    free(pathName);
    return false; 

  } else {
    // close the file and return true
    free(pathName);
    fclose(fp);
    return true;

  }

}


void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID){
  FILE *fp;
  if( pageDirectory != NULL && page != NULL){
    // construct the pathname for the page file in pageDirectory | 1 for size, 1 for / , 1 for log10
    char* pathName = malloc( sizeof(char) * (strlen(pageDirectory) +floor( (log10(docID))))  +3  );
    sprintf(pathName,"%s/%d", pageDirectory, docID);
    // open that file for writing
    if( ( fp = fopen(pathName, "w")) ==NULL ){
      free(pathName);

    } else {
      // print the URL
      fprintf(fp, "%s\n", webpage_getURL(page));
      // print the depth
      fprintf(fp, "%d\n", webpage_getDepth(page));
      // print the depthprint the contents of the webpage
      fprintf(fp, "%s\n", webpage_getHTML(page));
      // close the file
      free(pathName);
      fclose(fp);

    }
  }
}


bool pagedir_init(const char* pageDirectory){
  // construct the pathname for the .crawler file in that directory 
  // pagDirectory eg. = 
  if(pageDirectory == NULL){
    return false;
  }
  FILE *fp;

  char* pathName = malloc( sizeof(char) * (strlen(pageDirectory) + strlen("/.crawler") ) + 1 ); 

  sprintf(pathName, "%s/.crawler", pageDirectory); 
  // open the file for writing; on error -> return false
  if( ( fp = fopen(pathName, "w") ) == NULL){
    free(pathName);
    return false; 

  } else {
    // close the file and return true
    free(pathName);
    fclose(fp);
    return true;

  }

}

char* pagedir_int2char(const char* pageDirectory, const int docID){
char* pathName = malloc( sizeof(char) * (strlen(pageDirectory) +floor( (log10(docID))))  +3  );
    sprintf(pathName,"%s/%d", pageDirectory, docID);
    
return pathName; 

}

webpage_t* file2page(FILE* fp){

if(fp != NULL) {
  char* url = file_readLine(fp); 
  char* depth = file_readLine(fp);
  char* html = file_readFile(fp); 
  int pageDepth; 
  sscanf(depth, "%d", &pageDepth);

  webpage_t* page = webpage_new(url, pageDepth , html);
  free(depth);
  return page; 
} else {
  return NULL;
}
}






