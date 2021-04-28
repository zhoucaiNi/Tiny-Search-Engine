/*
 *
 * crawler.c
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "bag.h"
#include "mem.h"
#include "webpage.h"


static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);

int main(const int argc, char* argv[]){
  // checks for the right number of inputs // 
  if( argc != 4 ){
    fprintf(stderr, "pleased use a valid input :  ./crawler: seedURL pageDirectory maxDepth \n");
    exit(1);
  } else {
    // runs 
  }

}


