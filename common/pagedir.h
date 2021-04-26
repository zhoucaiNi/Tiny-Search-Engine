/*
 *
 * pagedir.h 
 *
 *
 */


/******** pagedir_int ********/
/* Construct the file name for .crawler files
 *
 * Opens the file for writing ; return false on error 
 * else close file and return true
 */

bool pagedir_init(const char* pageDirectory);

/******** pagedir_save ********/
/* 
 *
 */

void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID);
