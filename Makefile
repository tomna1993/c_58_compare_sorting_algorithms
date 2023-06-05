CC := gcc
#CFLAGS := 
DEST := ./build/

sort1: sort1.c
	mkdir -p build
	$(CC) sort1.c -lcs50 -o $(DEST)/sort1 

sort2: sort1.c
	mkdir -p build
	$(CC) sort1.c -lcs50 -o $(DEST)/sort1

sort3: sort1.c
	mkdir -p build
	$(CC) sort1.c -lcs50 -o $(DEST)/sort1