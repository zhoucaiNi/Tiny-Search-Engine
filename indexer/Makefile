# Makefile for crawler
#
# Zhoucai Ni, CS 50 Lab 5 
#

# directories 
L = ../libcs50
LL = ../common

# programs
PROG = indexer 
PROG2 = indextest

OBJS = indexer.o 
OBJS2 = indextest.o

# libraries
LIB = $(L)/libcs50-given.a
LIB1 = $(LL)/common.a

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST
#TESTING = -APPTEST

DIR = ../crawler/data/letters-1
FILENAME  = index/letters-1.index

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I$(L) -I$(LL) 
MAKE = make
all: $(PROG) $(PROG2)

LLIBS = $(LIB1) $(LIB)

$(PROG): $(OBJS) $(LIB1) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LLIBS) -lm -o $@


$(PROG2): $(OBJS2) $(LIB1) $(LIB)
	$(CC) $(CFLAGS) $(OBJS2) $(LLIBS) -o $@


indexer.o: indexer.c 

indextest.o: indextest.c

.PHONY: test

test: indexer.c indextest.c
	bash -v ./indexTest.sh &> testing.out

valgrind: indexer.c 
	valgrind ./indexer $(DIR) $(FILENAME)

moreValgrind: indexer.c
	valgrind --leak-check=full --show-leak-kinds=all -v ./indexer $(DIR) $(FILENAME)

clean:   
	rm -f core
	rm -f vgcore.*
	rm -f *~
	rm -rf data
	rm -f *.o
	rm -f indexer
	rm -f indextest
	rm -f *.index
	rm -rf index
