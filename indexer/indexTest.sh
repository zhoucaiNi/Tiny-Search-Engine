#!/bin/sh
rm -rf index
mkdir index

PAGEDIRECTORY=../crawler/data
FILENAME=test.index

# test cases

./indexer $PAGEDIRECTORY/letters-10 index/letters-10.index letters-10.index

./indexer 

./indexer $PAGEDIRECTORY/letters-10 

./indexer wrongPageDirectory output.index

./indexer $PAGEDIRECTORY/letters-10 noindex/letters-10.index

./indexer wrongPageDirectory noindex/letters-10.index

# using indexer to read the files and turn into index

valgrind ./indexer $PAGEDIRECTORY/letters-1 index/letters-1.index

./indexer $PAGEDIRECTORY/letters-10 index/letters-10.index

./indexer $PAGEDIRECTORY/toscrape-0 index/toscrape-0.index

./indexer $PAGEDIRECTORY/toscrape-1 index/toscrape-1.index

./indexer $PAGEDIRECTORY/wikipedia-0 index/wikipedia-0.index

./indexer $PAGEDIRECTORY/wikipedia-1 index/wikipedia-1.index

# comparing the results of my index to the shared examples

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/letters-1.index index/letters-1.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/letters-10.index index/letters-10.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/toscrape-0.index index/toscrape-0.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/toscrape-1.index index/toscrape-1.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/wikipedia-0.index index/wikipedia-0.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/wikipedia-1.index index/wikipedia-1.index

# indextest my index into new_index

valgrind ./indextest index/letters-1.index index/newletters-1.index

./indextest index/letters-10.index index/newletters-10.index

./indextest index/toscrape-0.index index/newtoscrape-0.index

./indextest index/toscrape-1.index index/newtoscrape-1.index

./indextest index/wikipedia-0.index index/newwikipedia-0.index

./indextest index/wikipedia-1.index index/newwikipedia-1.index

# comparing my new_index with old index

~/cs50-dev/shared/tse/indexcmp index/letters-1.index index/newletters-1.index

~/cs50-dev/shared/tse/indexcmp index/letters-10.index index/newletters-10.index

~/cs50-dev/shared/tse/indexcmp index/toscrape-0.index index/newtoscrape-0.index

~/cs50-dev/shared/tse/indexcmp index/toscrape-1.index index/newtoscrape-1.index

~/cs50-dev/shared/tse/indexcmp index/wikipedia-0.index index/newwikipedia-0.index

~/cs50-dev/shared/tse/indexcmp index/wikipedia-1.index index/newwikipedia-1.index

exit 0
