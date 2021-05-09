#!/bin/sh
# rm test.index

PAGEDIRECTORY=../crawler/data
# FILENAME=test.index

./indexer $PAGEDIRECTORY/letters-1 letters-1.index

./indexer $PAGEDIRECTORY/letters-10 letters-10.index

./indexer $PAGEDIRECTORY/toscrape-0 toscrape-0.index

./indexer $PAGEDIRECTORY/toscrape-1 toscrape-1.index

./indexer $PAGEDIRECTORY/wikipedia-0 wikipedia-0.index

./indexer $PAGEDIRECTORY/wikipedia-1 wikipedia-1.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/letters-1.index letters-1.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/letters-10.index letters-10.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/toscrape-0.index toscrape-0.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/toscrape-1.index toscrape-1.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/wikipedia-0.index wikipedia-0.index

~/cs50-dev/shared/tse/indexcmp ~/cs50-dev/shared/tse/output/wikipedia-1.index wikipedia-1.index