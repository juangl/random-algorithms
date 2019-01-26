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
  const T& operator[](int index) const;
  int size() const;
  const vector<T>& getSortedArray();
 private:
  void buildMaxHeap();
  void maxHeapity(int index);
  vector<T> internalVector;
  int heapSize;
};

#endif