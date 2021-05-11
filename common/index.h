

#ifndef __INDEX_H
#define __INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "index.h"
#include "hashtable.h"
#include "counters.h"
#include "mem.h"

typedef struct index index_t;

// functions // 

/********* index_new *********/
/* makes a new index_t* and returns it 
 * 
 * input: takes num_slots to determine the number of set in hashtable
 * 
 * output: return index_t*
 *
 */
index_t* index_new(const int num_slots);

/********* index_insert *********/
/* inserts a word and it's docId into the index 
 * 
 *
 * output: return true if inserted successfully 
 * else return false
 */
bool index_insert(index_t* indx, const char* key, const int counter_key);

/********* index_save *********/
/* prints the index into a file name
 * 
 *
 * input: takes a index and the indxFileName 
 *
 * 
 */
bool index_save(index_t* indx, char* indexFileName); 

/********* index_delete *********/
/* deletes the index by freeing the index
 * 
 * 
 * input: a valid index_t* 
 *
 * output: returns true if it successfully deletes 
 * else return false
 */
bool index_delete(index_t* indx);

/********* file2index *********/
/* reads a formatted index file and turns it into a index_t* and return it
 * 
 *
 * input: the name of a indexFile as char* 
 *
 * output: returns a index_t* 
 */
index_t* file2index(char* oldIndexFile); 

#endif // __INDEX_H
