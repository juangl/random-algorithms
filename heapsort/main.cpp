#include <vector>
using namespace std;

#include "heap.cpp"
#include "../utils/printVector.cpp"

int main() {
  Heap<int> heapTest {23, 12, 4, 5, 2, 34, 1, 3, 34, 5,};
  heapTest.size();
  printVector(heapTest);
  return 0;
}