# Makefile for crawler
#
# Zhoucai Ni, CS 50 Lab 5 
#

# directories 
L = ../libcs50
LL = ../common

# programs
PROG = indexer 
OBJS = indexer.o 

# libraries
LIB = $(L)/libcs50-given.a
LIB1 = $(LL)/common.a

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST
#TESTING = -APPTEST

DIR = ../crawler/data/test
FILENAME  = test.index

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I$(L) -I$(LL) 
MAKE = make
LLIBS = $(LIB1) $(LIB)

$(PROG): $(OBJS) $(LIB1)
	$(CC) $(CFLAGS) $(OBJS) $(LLIBS) -lm -o indexer

all: indexer indextest

indexer.o: indexer.c 

.PHONY: test

test: indexer.c 
	bash -v ./indexTest.sh


valgrind: indexer.c 
	rm $(FILENAME)
	valgrind ./indexer $(DIR) $(FILENAME)

# test: testing.sh
# 	bash -v	./testing.sh &> testing.out

moreValgrind: indexer.c
	rm $(FILENAME)
	valgrind --leak-check=full --show-leak-kinds=all -v ./indexer $(DIR) $(FILENAME)

# valgrindTest: valgrind.sh
# 	bash -v ./valgrind.sh &> valgrind.out

clean:   
	rm -f core
	rm -f vgcore.*
	rm -f *~
	rm -rf data
	rm -f *.o
	rm -f indexer
	rm -f *.index
