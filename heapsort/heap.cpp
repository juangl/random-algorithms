#include "heap.h"
#include <algorithm>
#include <initializer_list>
#include <vector>

using namespace std;

template <typename T>
Heap<T>::Heap(initializer_list<T> init) {
  internalVector = init;
  heapSize = init.size();
  buildMaxHeap();
}

template <typename T>
typename vector<T>::iterator Heap<T>::begin() {
  return internalVector.begin();
}

template <typename T>
typename vector<T>::iterator Heap<T>::end() {
  return internalVector.start() + heapSize;
}

template <typename T>
T& Heap<T>::operator[](int index) {
  return internalVector[index];
}

template <typename T>
const T& Heap<T>::operator[](int index) const {
  return internalVector[index];
}

template <typename T>
int Heap<T>::size() const {
  return heapSize;
}

#define LEFT(i) (i * 2) + 1
#define RIGHT(i) (i * 2) + 2

template <typename T>
void Heap<T>::buildMaxHeap() {
  int lastNonLeaf = (heapSize / 2) - 1;
  for (int i = lastNonLeaf; i >= 0; i--) {
    maxHeapity(i);
  }
}

template <typename T>
void Heap<T>::maxHeapity(int index) {
  int leftChildIndex = RIGHT(index);
  int rightChildIndex = LEFT(index);

  int largest;
  if (leftChildIndex < heapSize && (*this)[leftChildIndex] > (*this)[index]) {
    largest = leftChildIndex;
  } else {
    largest = index;
  }

  if (rightChildIndex < heapSize &&
      (*this)[rightChildIndex] > (*this)[largest]) {
    largest = rightChildIndex;
  }

  if (largest != index) {
    T temp = (*this)[largest];
    (*this)[largest] = (*this)[index];
    (*this)[index] = temp;
    maxHeapity(largest);
  }
}

template <typename T>
const vector<T>& Heap<T>::getSortedArray() {
  for (int i = heapSize; i >= 2; i--) {
    iter_swap(internalVector.begin(), internalVector.begin() + i - 1);
    heapSize -= 1;
    maxHeapity(0);
  }

  return internalVector;
}