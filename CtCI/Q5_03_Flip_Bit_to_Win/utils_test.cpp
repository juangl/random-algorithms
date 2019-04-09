#include <cassert>
using namespace std;

#include "utils.cpp"

int main() {
  assert(testPosRight(2, 1));
  assert(!testPosRight(2, 0));
  assert(testPosRight(1, 0));

  assert(setBitRight(2, 0, true) == 3);
  assert(setBitRight(3, 0, false) == 2);
  assert(setBitRight(3, 0, true) == 3);
  assert(setBitRight(2, 0, false) == 2);
  return 0;
}
