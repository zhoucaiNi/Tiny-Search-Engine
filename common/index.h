

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

index_t* index_new(const int num_slots);


bool index_insert(index_t* indx, const char* key, const int counter_key);


void index_print(index_t* indx, FILE* fp, void (*itemprint)(FILE *fp, const char* key, void* item)); 



void index_delete(index_t* indx, void (*itemdelete)(void* item));

#endif // __HASHTABLE_H
