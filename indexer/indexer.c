/*
 * 
 *
 * indexer.c
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
#include "word.h"


// global functions //
static void parseArgs(const int argc, char* argv[], char** pageDirectory, char** indexFileName);
static index_t* indexBuild(char* pageDirectory);
static void indexPage(index_t* indx, webpage_t* page, const int docId);

// ******* main ******* // 

int main(const int argc, char* argv[])
{
  char* pageDirectory = NULL;
  char* indexFileName = NULL; 

  parseArgs(argc, argv, &pageDirectory, &indexFileName);
  index_t* index = indexBuild(pageDirectory);
  index_save(index, indexFileName);
  index_delete(index);

}


static void parseArgs(const int argc, char* argv[], char** pageDirectory, char** indexFileName)
{
  // check for right number of args

  if(argc != 3){
    fprintf(stderr, "invalid arguments | valid form: ./indexer pageDirectory indexFileName | see README.md for detail \n");
    exit(1);
  } else {
    // defensive programming
    if(argv[1] != NULL && argv[2] != NULL){
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
        fclose(fp);
        // 
      } else {
        // free(*pageDirectory);
        fprintf(stderr, "invalid indexFileName\n");
        exit(3);
      }
    } else {
      exit(4);
    }
  }
}

static index_t* indexBuild(char* pageDirectory)
{
  // defensive programming 
  if(pageDirectory != NULL){
    //  create a new 'index' object
    index_t* indx = index_new(500);
    FILE *fp; 
    int currId = 1; 
    char* fileName = pagedir_int2char(pageDirectory, currId);

    // loop over document ID numbers, counting from 1
    while( (fp = fopen(fileName, "r") ) != NULL ){

      webpage_t* currPage = NULL;
      //   load a webpage from the document file 'pageDirectory/id'
      //   if successful, 
      if( (currPage = file2page(fp)) != NULL){
        //     pass the webpage and docID to indexPage
        indexPage(indx, currPage, currId);
      }
      webpage_delete(currPage);
      currId++;
      free(fileName);
      fileName = pagedir_int2char(pageDirectory, currId);
      fclose(fp);

    }
    free(fileName);
    return indx;
  } else {
    return NULL;
  }


}


static void indexPage(index_t* indx, webpage_t* page, const int docId)
{

  //  steps through each word of the webpage
  // defensive programming
  if(indx != NULL && page != NULL){
    int pos = 0;
    char* currWord; 
    while ((currWord = webpage_getNextWord(page, &pos)) != NULL) {

      //    skips trivial words (less than length 3),
      if(strlen(currWord) >= 3){
        //    normalizes the word (converts to lower case),
        normalizeString(currWord);
        //    looks up the word in the index,
        //      adding the word to the index if needed
        //    increments the count of occurrences of this word in this docID 
        // all done in the index_insert
        index_insert(indx, currWord, docId); 
      }
      free(currWord);
    }
  }




}


