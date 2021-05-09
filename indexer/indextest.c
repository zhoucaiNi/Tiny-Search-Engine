/*
 * 
 * indextest.c
 *
 */


 #include <stdlib.h>
 #include <stdio.h>
 #include "index.c"
 #include "file.h"
 #include "word.h"

 static void parseArgs(const int argc, char* argv[], char** oldFileName, char** newFileName);
 
int main(const int argc, char* argv[]){

char* oldFileName = NULL;
char* newFileName = NULL; 

parseArgs(argc, argv, &oldFileName, &newFileName);
// printf("making index\n");
index_t* index = file2index(oldFileName);
// printf("saving index\n");
index_save(index, newFileName);
// printf("deleting index\n");
index_delete(index);

}


static void parseArgs(const int argc, char* argv[], char** oldFileName, char** newFileName){

if(argc != 3){
  fprintf(stderr, "invalid arguments | valid format: ./indextest oldFileName newFileName\n");
  exit(1);
} else {
  FILE *fp;
    if((fp = fopen(argv[1], "r") ) != NULL){
      *oldFileName = argv[1];
      fclose(fp);
      // 
    } else {
      free(*oldFileName);
      fprintf(stderr, "invalid oldFileName\n");
      exit(2);
    }

    if((fp = fopen(argv[2], "w") ) != NULL){
      *newFileName = argv[2];
      fclose(fp);
      // 
    } else {
      free(*oldFileName);
      fprintf(stderr, "invalid newFileName\n");
      exit(3);
    }

}

}



