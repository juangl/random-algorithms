#ifndef HEAP_H
#define HEAP_H

#include <initializer_list>
#include <vector>
using namespace std;

template <typename T>
class Heap {
 public:
  Heap(initializer_list<T> init);
  typename vector<T>::iterator begin();
  typename vector<T>::iterator end();
  T& operator[](int index);
  int size();

 private:
  void buildMaxHeap();
  void maxHeapity(int index);
  int left(int i);
  int right(int i);
  vector<T> internalVector;
  int heapSize;
};

#endif