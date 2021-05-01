#!/bin/sh
rm -rf data/
mkdir data/

TEST_DIR=../../shared/tse/output
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



# wikipedia dpeth 0 & 1 
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

