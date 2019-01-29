#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#include "../utils/printVector.cpp"
#include "../heap/heap.cpp"
#include "../utils/isSorted.cpp"

int main() {
  MaxHeap<int> heapTest{
      23, 12, 4, 5, 2, 34, 1, 3, 34, 5,
  };
  heapTest.size();
  cout << "heap:\n";
  printVector(heapTest);

  vector<int> sorted = heapTest.getSortedArray();
  cout << "sorted array:\n";
  printVector(sorted);
  assert(isSorted(sorted));
  return 0;
}