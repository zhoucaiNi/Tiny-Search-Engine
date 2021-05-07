/*
 * 
 *
 * indexer.c
 *
 *
 *
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "webpage.h"
#include "mem.h"
#include "hashtable.h"
#include "index.h"
#include "pagedir.h"


// global functions //
static void parseArgs(const int argc, char* argv[], char** pageDirectory, char** indexFileName);
static index_t* indexBuild(char* pageDirectory, char* indexFileName);
// static void indexPage(webpage_t* page, const int docId);

// ******* main ******* // 

int main(const int argc, char* argv[])
{
  char* pageDirectory = NULL;
  char* indexFileName = NULL; 

  parseArgs(argc, argv, &pageDirectory, &indexFileName);
  index_t* index = indexBuild(pageDirectory, indexFileName);

}


static void parseArgs(const int argc, char* argv[], char** pageDirectory, char** indexFileName)
{
  // check for right number of args

  if(argc != 3){
    fprintf(stderr, "invalid arguments | valid form: ./indexer pageDirectory indexFileName | see README.md for detail \n");
    exit(1);
  } else {
    // check for valid pageDirectory 
    if( pagedir_validate(argv[1] )) {

      *pageDirectory = argv[1];
    } else {
      fprintf(stderr, "invalid pageDirectory (no .crawler file)\n");
      exit(2); 
    }
    // checks for writable file name 
    FILE *fp;
    if((fp = fopen(argv[2], "w") ) != NULL){
      *indexFileName = argv[2];
      // 
    } else {
fprintf(stderr, "invalid indexFileName\n");
exit(3);
    }
  }
}

static index_t* indexBuild(char* pageDirectory, char* indexFileName)
{

  //  create a new 'index' object
  index_t* indx = index_new(500);
 FILE *fp; 
 int currId = 1; 
 char* fileName = pagedir_int2char(pageDirectory, currId);

    // loop over document ID numbers, counting from 1
while( (fp = fopen(fileName, "r") ) != NULL ){
  printf("%s\n", fileName);

  
    //   load a webpage from the document file 'pageDirectory/id'
    //   if successful, 
    //     pass the webpage and docID to indexPage
    free(fileName);
    currId++;
    fileName = pagedir_int2char(pageDirectory, currId);
}

    return indx;
}


// static void indexPage(webpage_t* page, const int docId)
// {

  //  steps through each word of the webpage,
  //    skips trivial words (less than length 3),
  //    normalizes the word (converts to lower case),
  //    looks up the word in the index,
  //      adding the word to the index if needed
  //    increments the count of occurrences of this word in this docID


// }


webpage_t* file2page(FILE* fp){

  char* url; 
  char* depth; 
  webpage_t* page = webpage_new();
}