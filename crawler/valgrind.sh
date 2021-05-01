#!/bin/sh
rm -rf data/test
# File to test memory 
# normal make valgrind
make valgrind 

# invalid arg valgrind 
valgrind ./crawler NULL NULL NULL

# invalid dir
valgrind ./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html invalid_dir 5

# depth range out of bound
valgrind ./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html data/test 45


exit 0
