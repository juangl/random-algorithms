#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#include "../utils/printVector.cpp"
#include "functional-heap.cpp"
#include "../utils/isSorted.cpp"

int main() {
  HeapVector<int> heapTest{
      23, 12, 4, 5, 2, 34, 1, 3, 34, 5,
  };
  buildHeap(heapTest);

  cout << "heap:\n";
  printVector(heapTest);

  heapSort(heapTest);
  cout << "sorted array:\n";
  printVector(heapTest);
  assert(isSorted(heapTest));
  return 0;
}