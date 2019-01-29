#include <algorithm>
#include <initializer_list>
#include <vector>

using namespace std;

#define LEFT(i) (i * 2) + 1
#define RIGHT(i) (i * 2) + 2

template <typename T>
bool compareMaxHeap(T a, T b) {
  return a > b;
}

template <typename T>
bool compareMinHeap(T a, T b) {
  return a < b;
}

template <typename T, bool compareFn(T, T)>
class Heap {
 public:
  Heap(initializer_list<T> init) {
    internalVector = init;
    heapSize = init.size();
    buildHeap();
  }
  typename vector<T>::iterator start() { return internalVector.begin(); }
  typename vector<T>::iterator end() {
    return internalVector.start() + heapSize;
  }
  T& operator[](int index) { return internalVector[index]; }
  const T& operator[](int index) const { return internalVector[index]; }
  int size() const { return heapSize; }
  const vector<T>& getSortedArray() {
    for (int i = heapSize; i >= 2; i--) {
      iter_swap(internalVector.begin(), internalVector.begin() + i - 1);
      heapSize -= 1;
      heapity(0);
    }

    return internalVector;
  }

 private:
  void buildHeap() {
    int lastNonLeaf = (heapSize / 2) - 1;
    for (int i = lastNonLeaf; i >= 0; i--) {
      heapity(i);
    }
  }
  void heapity(int index) {
    int leftChildIndex = RIGHT(index);
    int rightChildIndex = LEFT(index);

    int largest;
    if (leftChildIndex < heapSize &&
        compareFn((*this)[leftChildIndex], (*this)[index])) {
      largest = leftChildIndex;
    } else {
      largest = index;
    }

    if (rightChildIndex < heapSize &&
        compareFn((*this)[rightChildIndex], (*this)[largest])) {
      largest = rightChildIndex;
    }

    if (largest != index) {
      T temp = (*this)[largest];
      (*this)[largest] = (*this)[index];
      (*this)[index] = temp;
      heapity(largest);
    }
  }
  vector<T> internalVector;
  int heapSize;
};

template <typename T>
using MaxHeap = Heap<T, compareMaxHeap>;

template <typename T>
using MinHeap = Heap<T, compareMinHeap>;