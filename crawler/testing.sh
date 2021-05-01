#!/bin/sh
rm -rf data/
mkdir data/
mkdir data/test_cases

TEST_DIR=../../shared/tse/output
URL=http://cs50tse.cs.dartmouth.edu/tse/letters/index.html 
# test cases 
# invalid args

# no args
./crawler 

# invalid directory
./crawler $URL invalid_dir 3

# invalid external url
./crawler https://home.dartmouth.edu/ data/test_cases 1

# invalid depth 
./crawler $URL data/test_cases -1 

./crawler $URL data/test_cases 11

# NULL 

./crawler NULL NULL NULL

# Regression testing

# letters depth 1 & 10 
URL=http://cs50tse.cs.dartmouth.edu/tse/letters/index.html 
echo "letters-0"
mkdir data/letters-1

./crawler $URL data/letters-1 1

diff -r $TEST_DIR/letters-1 data/letters-1

# depth 10
echo "letters-10"
mkdir data/letters-10
./crawler $URL data/letters-10 10

diff -r $TEST_DIR/letters-10 data/letters-10


#toscrape depth 0 & 1 
URL=http://cs50tse.cs.dartmouth.edu/tse/toscrape/index.html
echo "toscrape-1"
mkdir data/toscrape-0

./crawler $URL data/toscrape-0 0

diff -r $TEST_DIR/toscrape-0 data/toscrape-0

echo "toscrape-1"
mkdir data/toscrape-1
./crawler $URL data/toscrape-1 1

diff -r $TEST_DIR/toscrape-1 data/toscrape-1



# wikipedia depth 0 & 1 
URL=http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html
echo "wikipedia-0"
mkdir data/wikipedia-0
./crawler $URL data/wikipedia-0 0

diff -r $TEST_DIR/wikipedia-0 data/wikipedia-0

echo "wikipedia-1"
mkdir data/wikipedia-1
./crawler $URL data/wikipedia-1 1

diff -r $TEST_DIR/wikipedia-1 data/wikipedia-1


exit 0

