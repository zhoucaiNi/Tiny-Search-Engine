# Makefile for common library 
#
# Zhoucai Ni, cs50, lab 4 
#

# Object files, and target library

OBJS = pagedir.o ../libcs50/libcs50.a
LIB = common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb -lm $(FLAGS) -I../libcs50 
CC = gcc
MAKE = make

# Build $(LIB) by archving object files


$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

# Dependencies: object files
pagedir.o: pagedir.h

.PHONY: clean

clean: 
				rm -f core
				rm -f $(LIB) *~ *.o
