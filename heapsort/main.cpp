#include <vector>
#include <iostream>
using namespace std;

#include "../utils/printVector.cpp"
#include "heap.cpp"

int main() {
  Heap<int> heapTest{
      23, 12, 4, 5, 2, 34, 1, 3, 34, 5,
  };
  heapTest.size();
  cout << "heap:\n";
  printVector(heapTest);

  cout << "sorted array:\n";
  printVector(heapTest.getSortedArray());
  return 0;
}