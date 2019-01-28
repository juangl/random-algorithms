CC=g++
MD=mkdir
CFLAGS=-std=c++17

heapsort: main.cpp ../heap/heap.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f heapsort