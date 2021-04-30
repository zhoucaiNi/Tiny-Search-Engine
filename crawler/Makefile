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

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -lm -I$(L) -I$(LL)
CC = gcc
MAKE = make

$(PROG): $(OBJS) $(LIB) $(LIB1)
	$(CC) $(CFLAGS) $^ -o $@

crawler.o: crawler.c 

.PHONY: valgrind clean 

valgrind: crawler.c
	valgrind ./crawler http://cs50tse.cs.dartmouth.edu/tse/ test 3

clean: rm -f *~ *.0 *.dSYM 

