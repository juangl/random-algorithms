#include <cassert>
#include <vector>
#include "isSorted.cpp"

int main() {
  vector<int> sorted {3, 4, 5, 6};
  vector<int> unsorted { 2, 1, 2, 4, 1};
  assert(isSorted(sorted));
  assert(isSorted(unsorted) == false);
  return 0;
}
