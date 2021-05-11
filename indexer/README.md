# CS 50 LAB 5 Spring 2021 
## Index

### Compilation
To compile, simply `make`
To run indexer, simply `./indexer pageDirectory fileName`
To run indextest, simple `./indextester oldFileName newFileName`

### Usage

```c
static  void  parseArgs(const  int  argc, char* argv[], char** pageDirectory, char** indexFileName);
static  index_t* indexBuild(char* pageDirectory);
static  void  indexPage(index_t* indx, webpage_t* page, const  int  docId);
```

### Implementations
`parseArgs` -  filters the input and ensure the arguments are valid. Exit the program if invalid arugments are encountered. 

`indexBuild` - takes an `pageDirectory` and ouputs a `index_t`. This functions calls `indexPage`. 

`indexPage` - scans a page and insert it into the `index_t` 

### Assumptions
1. We assume that the file to read are in the format of 

 - url
 - depth
 - html content 
 
2. The names of files start at 1 and have no gaps in between the document IDs. 

### Files
* `Makefile` - compilation procedure
* `IMPLEMENTATION.md` - implementation file for indexer
* `indexer.c` - the implementation
* `indextest.c` - the 
* `indextest.sh` - bash file to perform the test 
* `testing.out` - result of `make test`

### Testing

The following test were done

 - basic invalid arguments
 - valgrind test
 - invalid number of arguments
 - comparing example files with indexer produced files
 - indexTesting 
