# CS 50 LAB 4 Spring 2021 
## Crawler

### Compilation

To compile, simply `make`.
To run, simply `./crawler`  `url`  `pagedirectory` `depth`
g
### Usage
The crawler.c file contains the following functions
```c
static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);
static void logr(const char *word, const int depth, const char *url)
```
`parseArgs` - filters the incoming arguments.

`crawl` - goes into provided `SeedURL` and checks for validity. It will then find all the linked URL on the page and repeat till it reach `maxDepth`. Calls the `pageScan` function

`pageScan` -  Given a webpage, scan the given page to extract any links (URLs), ignoring non-internal URLs; for any URL not already seen before (i.e., not in the hashtable), add the URL to both the hashtable pages_seen and to the bag pages_to_crawl

`logr` - logs the progress of the program in a readable format.

### Assumptions
All assumptions are the same as the specs provided

### Files

* `Makefile` - compilation procedure
* `crawler.c` - the implementation
* `testing.sh` - bash file to perform the test 
* `testing.out` - result of `make test`
* `valgrind.sh` - bash file to valgrind
* `valgrind.out` - result of `make valgrindTest`

### Testing 

Test Cases and Directory comparison `make test`	
The following were tested
 - Basic Null arguments
 - Edge cases with depth
 - Invalid URL, pageDirectory, external links. 
 - Regression test 
 
Memory check testing run `make valgrindTest`

#### Mem testing 
to do valgrind run `make valgrind`
to do valgrind with detail run `make moreValgrind`

