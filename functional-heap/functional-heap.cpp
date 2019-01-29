#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class HeapVector : public vector<T> {
 public:
  HeapVector(initializer_list<T> init) : vector<T>(init) {
    heapSize = init.size();
  }
  int getHeapSize() { return heapSize; }
  void setHeapSize(int newSize) { heapSize = newSize; }

 private:
  int heapSize = 0;
};

#define LEFT(i) (i * 2) + 1
#define RIGHT(i) (i * 2) + 2
#define PARENT(i) i / 2

template <typename T>
bool compareMaxHeap(const T a, const T b) {
  return a > b;
}

template <typename T>
bool compareMinHeap(const T a, const T b) {
  return a < b;
}

template <typename T>
void heapify(HeapVector<T>& A,
             int index,
             bool (*compareFn)(const T, const T) = compareMaxHeap) {
  int leftChildIndex = RIGHT(index);
  int rightChildIndex = LEFT(index);

  int largest;
  if (leftChildIndex < A.getHeapSize() &&
      compareFn(A[leftChildIndex], A[index])) {
    largest = leftChildIndex;
  } else {
    largest = index;
  }

  if (rightChildIndex < A.getHeapSize() &&
      compareFn(A[rightChildIndex], A[largest])) {
    largest = rightChildIndex;
  }

  if (largest != index) {
    T temp = A[largest];
    A[largest] = A[index];
    A[index] = temp;
    heapify(A, largest, compareFn);
  }
}

template <typename T>
void buildHeap(HeapVector<T>& A) {
  int lastNonLeaf = (A.getHeapSize() / 2) - 1;
  for (int i = lastNonLeaf; i >= 0; i--) {
    heapify(A, i);
  }
}

template <typename T>
T heapMaximum(const HeapVector<T>& A) {
  return A[0];
}

template <typename T>
T heapExtractMax(HeapVector<T>& A) {
  if (A.getHeapSize() < 1) {
    throw runtime_error("heap underflow");
  }
  T max = A[0];
  A[0] = A[A.getHeapSize() - 1];
  A.setHeapSize(A.getHeapSize() - 1);
  heapity(A, 0, compareMaxHeap);
  return max;
}

template <typename T>
void heapIncreaseKey(HeapVector<T>& A, int index, T key) {
  if (key < A[index]) {
    throw runtime_error("new key is smaller than current key");
  }
  A[index] = key;

  while (index > 0 && A[PARENT(index)] < A[index]) {
    swap(*(A.begin() + index), *(A.begin() + PARENT(index)));
    index = PARENT(index);
  }
}

template <typename T>
void maxHeapInsert(HeapVector<T>& A, T key) {
  A.setHeapSize(A.getHeapSize() + 1);
  A[A.heapSize() - 1] = key;
  heapIncreaseKey(A, A.getHeapSize() - 1, key);
}

template <typename T>
void heapSort(HeapVector<T>& A) {
  int heapSize = A.getHeapSize();

  for (int i = heapSize; i >= 2; i--) {
    swap(*A.begin(), *(A.begin() + i - 1));
    heapSize -= 1;
    A.setHeapSize(heapSize);
    heapify(A, 0);
  }
}