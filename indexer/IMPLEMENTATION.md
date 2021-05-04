# CS 50 TSE Indexer
## Implementation Spec

## Data structures
We use two data strctures: a `hashtable` of that points to the word as the key and `counters` as the item, the `counters` would keep track  of the frequency of words in count and the docID in key. Both starts empty. The size of the hashtable is impossible to determine in advance, so we use 200. 

`hashtable` -> `set` -> `counters`  

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