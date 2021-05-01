# Makefile for crawler
#
# Zhoucai Ni,  cs50 lab 4
#

# directories 
L = ../libcs50
LL = ../common

# programs
PROG = crawler
OBJS = crawler.o 

# libraries
LIB = $(L)/libcs50-given.a
LIB1 = $(LL)/common.a

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST
#TESTING = -APPTEST

URL = http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
DIR = data/test
DEPTH = 3

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I$(L) -I$(LL) 
CC = gcc
MAKE = make

$(PROG): $(OBJS) $(LIB) $(LIB1)
	$(CC) $(CFLAGS) $^ -lm -o $@

crawler.o: crawler.c 

.PHONY: valgrind moreValgrind test clean 

valgrind: crawler.c
	valgrind ./crawler $(URL) $(DIR) $(DEPTH) 

test: testing.sh
	bash -v	./testing.sh &> testing.out

moreValgrind: crawler.c
	mkdir $(DIR)
	valgrind --leak-check=full --show-leak-kinds=all -v ./crawler $(URL) $(DIR) $(DEPTH) 
clean:   
	rm -f core
	rm -f vgcore.*
	rm -f *~
	rm -rf data
	rm -f *.o
	rm -f crawler

