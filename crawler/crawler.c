/*
 *
 * crawler.c 
 * crawls a website and retrieves webpages starting with a specified URL.
 * It parses the initial webpage, extracts any embedded URLs and retrieves those pages,
 * and crawls the pages found at those URLs, but limiting itself to some threshold number of hops from
 * the seed URL, and avoiding visiting any given URL more than once. It saves the pages, and the URL and
 * depth for each, in files. When the crawler process is complete, the indexing of the collected documents can begin.
 * 
 *
 *
 */

#define APPTEST
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"
#include "bag.h"
#include "mem.h"
#include "webpage.h"
#include "pagedir.h"

// global functins // 
static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);
static void logr(const char *word, const int depth, const char *url);

//******* main *******// 

int main(const int argc, char* argv[]){
  // synax example:  ./crawler seedURL pageDirectory maxDepth 

  char* seedURL = NULL; 
  char* pageDirectory = NULL; 
  int maxDepth = 0; 
  parseArgs(argc, argv, &seedURL, &pageDirectory, &maxDepth );
  crawl(seedURL, pageDirectory, maxDepth);
  exit(0);
}

//******** parseArgs **********//
// Given arguments from the command line, extract them into the function parameters; return only if successful.

static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth){
  // checks for right number of arguments 

  if( argc != 4){
    fprintf(stderr, "invalid syntax | valid syntax: ./crawler seedURL pageDirectory maxDepth | check README.md for detail\n");
    exit(1);
  } else {
    // init the variables 

    // normalize and validate the URL // 
    *seedURL = normalizeURL(argv[1]);
    if( isInternalURL( *seedURL) == false){
      // url is not internal -> exits
      fprintf(stderr, "URL not internal\n");
      free(*seedURL);
      exit(2);
    }

    // checks the directory 
    if( pagedir_init(argv[2]) == false){
      fprintf(stderr, "Invalid pageDirectory\n");
      free(*seedURL);
      exit(3);
    }

    *pageDirectory = argv[2];

    // ensure maxDepth is a valid int 
    if(sscanf(argv[3], "%i", maxDepth) == 0){
      fprintf(stderr, "maxDepth value not valid\n");
      free(*seedURL);
      exit(4);
    };

    // check if the maxDepth is within the range 
    if( *maxDepth < 0 || *maxDepth > 10 ){
      fprintf(stderr, "maxDepth out of range | must be [0,10] \n");
      free(*seedURL);
      exit(5);
    }

  }

}

//******* crawl *******// 
//Do the real work of crawling from seedURL to maxDepth and saving pages in pageDirectory

static void crawl(char* seedURL, char* pageDirectory, const int maxDepth){


  char* firstURL = mem_malloc(sizeof(char) * strlen(seedURL) +1);

  strcpy(firstURL, seedURL);
  free(seedURL);

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
    //    printf("URL extracted: %s\n", webpage_getURL(currentPage));

    logr("Fetched", webpage_getDepth(currentPage), webpage_getURL(currentPage));
    // 	fetch the HTML for that webpage
    if( !webpage_fetch(currentPage)) { 
      webpage_delete(currentPage);
    } else {
      pagedir_save(currentPage, pageDirectory, id);

      //	if fetch was successful,
      //		save the webpage to pageDirectory
      pagedir_save(currentPage, pageDirectory, id);

      //		if the webpage is not at maxDepth,
      if(webpage_getDepth(currentPage) < maxDepth){

        //			pageScan that HTML
        //       printf("Scanning URL: %s\n", webpage_getURL(currentPage));
        // logr("scanning", currentPage->depth, currentPage->url); 

        logr("Scanning", webpage_getDepth(currentPage), webpage_getURL(currentPage));
        pageScan(currentPage, toCrawl, visited);
      }

      //	delete that webpage
      webpage_delete(currentPage);
      id++;


    }
  }

  // delete the bag
  bag_delete(toCrawl, webpage_delete);

  // delete the hashtable
  hashtable_delete(visited, NULL );
  //  mem_free(firstURL);


}

static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen){
  // while there is another URL in the page
  char* url; 
  char* normUrl;
  int depth  = webpage_getDepth(page) + 1;
  int pos = 0; 
  char* item = "s";

  while( (url =  webpage_getNextURL(page, &pos)) != NULL){

    //	if that URL is Internal,
    if( (normUrl = normalizeURL(url)) != NULL){

      if( isInternalURL(url) ) { 
        // if it's alrady in the table then 
        if( hashtable_find(pagesSeen, url) == NULL) {
          //		insert the webpage into the hashtable

          if(    hashtable_insert(pagesSeen, normUrl, item ) == true ){  
            //		if that succeeded,
            logr("Inserting", depth, normUrl);

            char* memUrl = mem_malloc(sizeof(char) * strlen(normUrl) + 1);
            strcpy(memUrl, normUrl);

            //			create a webpage_t for it
            webpage_t *newPage = webpage_new(memUrl, depth, NULL); 

            //			insert the webpage into the bag
            bag_insert(pagesToCrawl, newPage);
          }

        } else{
          logr("IgnDupl", depth, normUrl);
        }
      } else {
        logr("IgnExtrn", depth,normUrl);
      }

    }
    //	free the URL
    free(normUrl);
    free(url);
  }



}

//***** logr *******/
// Just log the process in a nice format
// log one word (1-9 chars) about a given url
static void logr(const char *word, const int depth, const char *url)
{
#ifdef APPTEST
  printf("%2d %*s%9s: %s\n", depth, depth, "", word, url);
#else
  ;
#endif
}



