# CS 50 LAB 4 SPRING 2021
# Common

## files 
*`Makefile` - compilation procedure
*`pagedir.c`- the implementation
*`pagedir.h`- the interface

## pagedir.h 

### usage
the pagedir.h file have these function
```c 
bool pagedir_init(const char* pageDirectory);
void pagedir_save(const webpage_t* page, const char* pageDirectory, const int docID);
```
`pagedir_init` check the validity of a file directory `pageDirectory` by creating a .crawler file in the directory. Returns either false when page directory is valid and true when it's valid. 

`pagedir_save` takes in a webpage struct `page` and writes it's contents into a file directory `pageDictory` using the provided name `docID`

### Testing
Testing is done in the crawler directory. 

