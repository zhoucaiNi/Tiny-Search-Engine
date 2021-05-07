/*
 *
 * pagedir.h 
 * We create a re-usable module pagedir.c to handles the pagesaver mentioned in 
 * the design (writing a page to the pageDirectory), and marking it as a Crawler-produced pageDirectory 
 * (as required in the spec). We chose to write this as a separate module, in ../common, to encapsulate all 
 * the knowledge about how to initialize and validate a pageDirectory, and how to write and read page files, 
 * in one place... anticipating future use by the Indexer and Querier.
 */
#include <math.h>

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

char* pagedir_int2char(const char* pageDirectory,const int docID);

