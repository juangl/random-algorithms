CC=g++
MD=mkdir
CFLAGS=-std=c++17 -g

quickSort: main.cpp quickSort.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f heapsort