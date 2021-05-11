# CS 50 LAB 4 SPRING 2021
# Common Directory

## files 

 - `Makefile` - compilation procedure
 - `pagedir.c`- the implementation
 - `pagedir.h`- the interface
 - `index.c` - the implementation of a index data type
 - `index.h` - the interface
 - `word.c` - the implementation
 - `word.h` - the interface

## pagedir.h 

### usage
the pagedir.h file have these function
```c 
bool pagedir_init(const char* pageDirectory);
void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID);
char* pagedir_int2char(const  char*  pageDirectory,const  int  docID);
webpage_t* file2page(FILE*  fp);
bool  pagedir_validate(const  char*  pageDirectory);
```
### Implementation
`pagedir_init` check the validity of a file directory `pageDirectory` by creating a .crawler file in the directory. Returns either false when page directory is valid and true when it's valid. 

`pagedir_save` takes in a webpage struct `page` and writes it's contents into a file directory `pageDictory` using the provided name `docID`

## index.h
the index.h files have these functions
```c
index_t*  index_new(const  int  num_slots);
bool  index_insert(index_t*  indx, const  char*  key, const  int  counter_key);
bool  index_save(index_t*  indx, char*  indexFileName);
bool  index_delete(index_t*  indx);
index_t* file2index(char* oldIndexFile); 
```
### Implementation
`index_new` create a index (wrapper of `hashtable`) and takes in a argument for the `num_slots` of the `hashtable` 

`index_insert` - inserts `key` (word) and `counter_key` (docID).

`index_save`- takes an `index_t` and `fileName` to print the entire index into a file. 

`index_delete` - free the memory allocated for the index

`file2index`  - turns a index file into a index_t* and returns it. 

## word.h 
the word.h files have these function
```c
bool  normalizeString(char*  str);
```
### Implementation
`normalizeString` - takes an `char*` and turns it lower case

### Testing
Testing is done in the crawler and indexer directory. 

