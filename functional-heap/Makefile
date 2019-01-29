CC=g++
MD=mkdir
CFLAGS=-std=c++17 -g

functional-heapsort: main.cpp functional-heap.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f heapsort