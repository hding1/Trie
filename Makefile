PROG=prog1
CC=g++
CPPFLAGS=-g -Wall -std=c++11

.PHONY: all

all:
	$(CC) $(CPPFLAGS) main.cpp Tree.cpp Word.cpp -o $(PROG)

clean:
	rm -f *.o $(PROG) core
