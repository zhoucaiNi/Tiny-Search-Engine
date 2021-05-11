# CS 50 TSE Indexer
## Implementation Spec

## Data structures
We use two data strctures: a `hashtable` and `counter` to make a new data structure `index`

The key data structure is the `index`, mapping from _word_ to _(docID, #occurrences)_ pairs. The _index_ is a _hashtable_ keyed by _word_ and storing _counters_ as items. The _counters_ is keyed by _docID_ and stores a count of the number of occurrences of that word in the document with that ID.

`Index` = `hashtable` -> `set` -> `counters`  

## Control flow
### main 
The `main` function simply calls `parseArgs` and `index`, then exits zero. 

### parseArgs
Given arguments from the command line, extract them into the function parameter; return only if successful.
 - for `pageDirectory`, checks that is the directory produced by the crawler.
 - for `indexFileName`, ensure that is the pathname of a file that can be written. 
 - if any trouble is found, print an error to stderr and exit non-zero. 

### indexBuild
Builds an in-memory index from webpage files it finds in the pageDirectory. 
Pseudocode:
```
  create a new 'index' object
  loop over document ID numbers, counting from 1
    load a webpage from the document file 'pageDirectory/id'
    if successful, 
      pass the webpage and docID to indexPage
```

### indexPage
scans a webpage document to add its words to the index.
Pseudocode (From DESIGN.md):
```
 steps through each word of the webpage,
   skips trivial words (less than length 3),
   normalizes the word (converts to lower case),
   looks up the word in the index,
     adding the word to the index if needed
   increments the count of occurrences of this word in this docID
```


## Function prototypes 
### indexer
```c
int main(const int argc, char* argv[]);
static void parseArgs(const int argc, char* argv[], char** pageDirectory, char** indexFileName);
static void indexBuild(char* pageDirectory, char* indexFileName);
static void indexPage(webpage_t* page, const int docId);
```

## Error handling and recovery

## Testing plan

_Unit testing_. A program  _indextest_  will serve as a unit test for the  _index_  module; it reads an index file into the internal  _index_  data structure, then writes the index out to a new index file.

_Integration testing_. The  _indexer_, as a complete program, will be tested by building an index from a pageDirectory, and then the resulting index will be validated by running it through the  _indextest_  to ensure it can be loaded.

1.  Test  `indexer`  with various invalid arguments. 2. no arguments 3. one argument 4. three or more arguments 5. invalid  `pageDirectory`  (non-existent path) 5. invalid  `pageDirectory`  (not a crawler directory) 6. invalid  `indexFile`  (non-existent path) 7. invalid  `indexFile`  (read-only directory) 7. invalid  `indexFile`  (existing, read-only file)
2.  Run  _indexer_  on a variety of pageDirectories and use  _indextest_  as one means of validating the resulting index.
3.  Run  _valgrind_  on both  _indexer_  and  _indextest_  to ensure no memory leaks or errors.