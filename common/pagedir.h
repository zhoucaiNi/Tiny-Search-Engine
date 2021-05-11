/*
 *
 * pagedir.h 
 * We create a re-usable module pagedir.c to handles the pagesaver mentioned in 
 * the design (writing a page to the pageDirectory), and marking it as a Crawler-produced pageDirectory 
 * (as required in the spec). We chose to write this as a separate module, in ../common, to encapsulate all 
 * the knowledge about how to initialize and validate a pageDirectory, and how to write and read page files, 
 * in one place... anticipating future use by the Indexer and Querier.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "webpage.h"
#include "file.h"

/******** pagedir_validate ********/
/* checks if the directory contain .crawler files
 * 
 * 
 * Return:
 * If there is .crawler file return true else false
 */

bool pagedir_validate(const char* pageDirectory);

/******** pagedir_int ********/
/* Construct the file name for .crawler files
 * 
 * 
 * Return:
 * Opens the file for writing ; return false on error 
 * else close file and return true
 */

bool pagedir_init(const char* pageDirectory);

/******** pagedir_save ********/
/* 
 * Makes a file with the docID name and print the following in this order
 * 
 * `URL
 *  Depth
 *  HTML`
 *
 * User input
 * valid webpage_t* , pageDirectory (existing), docID (name of the file to create)
 *
 *
 * Returns void
 */

void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID);


/******** pagedir_int2char ********/
/* takes an pageDirectory and a docID, combines the two and return the char* 
 * 
 * 
 * Return:
 * if successfully convert the arguments into one char* return that char* 
 * else return NULL
 */

char* pagedir_int2char(const char* pageDirectory,const int docID);

/******** file2page ********/
/* takes an FILE* and returns a webpage_t* 
 * 
 * 
 * Return:
 * if successful return the webpage_t with the content of the FILE* 
 * else return NULL
 */
webpage_t* file2page(FILE* fp); 

