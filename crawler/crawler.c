/*
 *
 * crawler.c
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"
#include "bag.h"
#include "mem.h"
#include "webpage.h"
#include "pagedir.h"

// global functins // 
static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);

int main(const int argc, char* argv[]){
  // synax example:  ./crawler seedURL pageDirectory maxDepth 
  // char* seedURL = mem_malloc( (sizeof(char) * strlen(argv[1]) + 1));
  // char* pageDirectory = mem_malloc( (sizeof(char) * strlen(argv[2]) + 1));
  // int* maxDepth = mem_malloc( sizeof(int) ); 
  char** seedURL = mem_malloc( sizeof(char*)); 
  char** pageDirectory = mem_malloc( sizeof(char*));
  int* maxDepth = mem_malloc( sizeof(int));
  parseArgs(argc, argv, seedURL, pageDirectory, maxDepth );
  crawl(*seedURL, *pageDirectory, *maxDepth);
  exit(0);
}

static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth){
  // checks for right number of arguments 

  if( argc != 4){
    fprintf(stderr, "invalid syntax | valid syntax: ./crawler seedURL pageDirectory maxDepth | check README.md for detail\n");
    exit(1);
  } else {
    // init the variables 
    //  *seedURL = mem_malloc( (sizeof(char) * strlen(argv[1]) + 1 ));

    // normalize and validate the URL // 
    //    *seedURL = normalizeURL(*seedURL);
    if( isInternalURL( normalizeURL(argv[1])) == false){
      // url is not internal -> exits
      fprintf(stderr, "URL not internal\n");
      exit(1);
    }
    //  *seedURL = mem_malloc( (sizeof(char) * strlen(argv[1]) + 1));
    //  **seedURL = argv[1];
    *seedURL = argv[1];

    // checks the directory 
    if( pagedir_init(argv[2]) == false){
      fprintf(stderr, "Invalid pageDirectory\n");
      exit(1);
    }

    *pageDirectory = argv[2];

    // ensure maxDepth is a valid int 
    if(sscanf(argv[3], "%i", maxDepth) == 0){
      fprintf(stderr, "maxDepth value not valid\n");
      exit(1);
    };

    // check if the maxDepth is within the range 
    if( *maxDepth < 0 || *maxDepth > 10 ){
      fprintf(stderr, "maxDepth out of range | must be [0,10] \n");
      exit(1);
    }

  }

}


static void crawl(char* seedURL, char* pageDirectory, const int maxDepth){


  char* firstURL = mem_malloc(sizeof(char) * strlen(seedURL) +1);
  strcpy(firstURL, seedURL);

  char* item = "s";

  // initialize the hashtable and add the seedURL
  hashtable_t *visited = hashtable_new(200);
  hashtable_insert(visited, firstURL, item);

  // initialize the bag and add a webpage representing the seedURL at depth 0
  bag_t *toCrawl = bag_new();
  webpage_t *firstPage = webpage_new(firstURL, 0, NULL);

  bag_insert(toCrawl, firstPage);

  // init
  webpage_t *currentPage; 
  int id = 1;
  // while bag is not empty
  while( (currentPage = bag_extract(toCrawl) ) != NULL ){
    //	pull a webpage from the bag

    // 	fetch the HTML for that webpage
    if( !webpage_fetch(currentPage)) { 
webpage_delete(currentPage);
    } else {
      pagedir_save(currentPage, pageDirectory, id);

      //	if fetch was successful,
      //		save the webpage to pageDirectory
      //      printf("%d\n", webpage_getDepth(currentPage));
      pagedir_save(currentPage, pageDirectory, id);

      //		if the webpage is not at maxDepth,
      if(webpage_getDepth(currentPage) < maxDepth){

        //			pageScan that HTML
        pageScan(currentPage, toCrawl, visited);
      }

      //	delete that webpage
      webpage_delete(currentPage);
      id++;



      // delete the hashtable
    
    }
  }

      hashtable_delete(visited, webpage_delete);
  // delete the bag
  bag_delete(toCrawl, webpage_delete);
  mem_free(firstURL);


}

static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen){
  // while there is another URL in the page
  char* url; 
  int depth  = webpage_getDepth(page) + 1;
  int pos = 0; 
  char* item = "s";

  while( (url =  webpage_getNextURL(page, &pos)) != NULL){
    //	if that URL is Internal,
    if( (url = normalizeURL(url)) != NULL){

      if( isInternalURL(url) ) { 
        // if it's alrady in the table then 
        if( hashtable_find(pagesSeen, url) == NULL) {
          //		insert the webpage into the hashtable
          if(    hashtable_insert(pagesSeen, url, item ) == true ){  
            webpage_t *newPage = webpage_new(url, depth, NULL); 
            bag_insert(pagesToCrawl, newPage);
          }

        }
      } else {

      }

    }
    free(url);
  }

  //		if that succeeded,
  //			create a webpage_t for it
  //			insert the webpage into the bag
  //	free the URLZZ


}

