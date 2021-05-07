# Makefile for common library 
#
# Zhoucai Ni, cs50, lab 4 
#

# Object files, and target library

OBJS = pagedir.o index.o word.o ../libcs50/libcs50-given.a
LIB = common.a 

CFLAGS = -Wall -pedantic -std=c11 -ggdb -lm -I../libcs50
CC = gcc
MAKE = make

# Build $(LIB) by archving object files

$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

# Dependencies: object files
pagedir.o: pagedir.h
index.o: index.h ../libcs50/counters.h ../libcs50/file.h ../libcs50/hashtable.h
word.o: word.h


.PHONY: clean

clean: 
				rm -f core
				rm -f $(LIB) *~ *.o
