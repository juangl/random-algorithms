#include <cassert>
#include <iostream>
#include <vector>
#include "../utils/isSorted.cpp"
#include "../utils/printVector.cpp"
#include "quicksort.cpp"

using namespace std;

int main() {
  vector<int> arr{
      23, 34, 1, 23, 4, 5, 62, 15, 3, 34, 67, 8, 6,
  };

  cout << "unsorted:" << endl;
  printVector(arr);

  cout << partition(arr, 0, arr.size() - 1) << endl;

  quickSort(arr, 0, arr.size() - 1);
  cout << "sorted:" << endl;
  printVector(arr);

  assert(isSorted(arr));
  return 0;
}