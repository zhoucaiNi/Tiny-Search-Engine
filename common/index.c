/*
 *
 * index.c 
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "index.h"
#include "hashtable.h"
#include "counters.h"
#include "mem.h"

/******** local ********/
void tablesave(void *arg, const char* key, void* item);
void countsave(void *arg, const int key, const int count);

/******** global ********/

bool index_insert(index_t* indx, const char* key, const int counter_key);
void index_save(index_t* indx, FILE* fp); 
void index_delete(index_t* indx, void (*itemdelete)(void* item));

/****** local *******/ 

// helper function to iterate the counters 
void tablesave(void *arg, const char* key, void* item){
FILE* fp = arg;
fprintf(fp, "%s ", key);
counters_iterate(item, fp, countsave);

}


void countsave(void *arg, const int key, const int count){
FILE* fp = arg;
fprintf(fp, "%d %d ", key, count);

}

typedef struct index{
  hashtable_t* hashtable;

} index_t;

  index_t*
index_new(const int num_slots)
{
  index_t* indx = mem_malloc(sizeof(index_t));
  if ( indx == NULL ) {
    return NULL;
  } else {
    indx->hashtable = hashtable_new(num_slots);
    return indx;
  } 

  return NULL;
} 

  bool
index_insert(index_t* indx, const char* key, const int counter_key)
{

  // defensive programming
  if( indx == NULL && key == NULL && counter_key == 0){
    // Find the item associated with the key
    counters_t* wordCount = hashtable_find(indx->hashtable, key);
    // If return NULL, insert the key with a counter using the counter_key
    if(wordCount == NULL){
      wordCount = counters_new();
      counters_add(wordCount, counter_key);
      hashtable_insert(indx->hashtable, key, wordCount);
      return true;
      // Else add the DocID to the retrieved counter
    } else {
      counters_add(wordCount, counter_key);
      return true; 
    }
  }
  return false; 
} 

  void
index_save(index_t* indx, FILE* fp )
{
hashtable_iterate( indx->hashtable, fp, tablesave);

}


