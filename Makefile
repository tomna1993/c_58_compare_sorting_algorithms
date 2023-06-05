CC := gcc
#CFLAGS := 
DEST := ./build/

all: clean sort1 sort2 sort3 sort4

sort1: sort1.c
	mkdir -p build
	$(CC) sort1.c -lcs50 -o $(DEST)/sort1 

sort2: sort2.c
	mkdir -p build
	$(CC) sort2.c -lcs50 -o $(DEST)/sort2

sort3: sort3.c
	mkdir -p build
	$(CC) sort3.c -lcs50 -o $(DEST)/sort3

sort4: sort4.c
	mkdir -p build
	$(CC) sort4.c -lcs50 -o $(DEST)/sort4

clean:
	rm -rf $(DEST)