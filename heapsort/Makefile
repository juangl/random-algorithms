CC=g++
MD=mkdir
CFLAGS=-std=c++17
DEPS = heap.h
ODIR=make_obj

_OBJ = $(patsubst %.h,%.o,$(DEPS)) 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: make_directories heapsort

$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

heapsort: main.cpp $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

make_directories: $(ODIR)

$(ODIR):
	$(MD) -p $(ODIR)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o heapsort
	rmdir $(ODIR)