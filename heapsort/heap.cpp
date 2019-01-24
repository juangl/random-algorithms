#include "heap.h"
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
int Heap<T>::size() {
  return heapSize;
}

template <typename T>
int Heap<T>::left(int i) {
  return i * 2 + 1;
}

template <typename T>
int Heap<T>::right(int i) {
  return i * 2 + 2;
}

template <typename T>
void Heap<T>::buildMaxHeap() {
  int lastNonLeaf = (heapSize / 2) - 1;
  for (int i = lastNonLeaf; i <= 0; i--) {
    maxHeapity(i);
  }
}

template <typename T>
void Heap<T>::maxHeapity(int index) {
  int leftChildIndex = left(index);
  int rightChildIndex = right(index);

  int largest;
  if (leftChildIndex < heapSize && (*this)[leftChildIndex] > (*this)[index]) {
    largest = leftChildIndex;
  } else {
    largest = index;
  }

  if (rightChildIndex < heapSize &&
      (*this)[rightChildIndex > (*this)[largest]]) {
    largest = rightChildIndex;
  }

  if (largest != index) {
    T temp = (*this)[largest];
    (*this)[largest] = (*this)[index];
    (*this)[index] = temp;
    maxHeapity(largest);
  }
}