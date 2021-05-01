# CS 50 LAB 4 Spring 2021 
## Crawler

### Compilation

To compile, simply `make`.
To run, simply `./crawler url pagedirectory depth`

### Usage
The crawler.c file contains the following functions
```c
static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);
static void logr(const char *word, const int depth, const char *url)
```

### Files

* `Makefile` - compilation procedure
* `crawler.c` - the implementation
* `testing.sh` - bash file to perform the test 
* `testing.out` - result of `make test`

### Testing 

to do valgrind run `make valgrind`
to do valgrind with detail run `make moreValgrind`

