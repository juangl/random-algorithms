#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#include "../utils/printVector.cpp"
#include "heap.cpp"
#include "../utils/isSorted.cpp"

int main() {
  Heap<int> heapTest{
      23, 12, 4, 5, 2, 34, 1, 3, 34, 5,
  };
  heapTest.size();
  cout << "heap:\n";
  printVector(heapTest);

  vector<int> sorted = heapTest.getSortedArray();
  assert(isSorted(sorted));
  cout << "sorted array:\n";
  printVector(sorted);
  return 0;
}