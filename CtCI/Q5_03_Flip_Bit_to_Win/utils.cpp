#include <cstdint>
#include <iostream>
using namespace std;

bool testPosRight(uint32_t number, unsigned int pos) {
  uint32_t mask = 1;
  mask <<= pos;
  return mask & number;
}

uint32_t setBitRight(uint32_t number, unsigned int pos, bool val) {
  uint32_t mask = ~(1 << pos);
  uint32_t bit = val ? 1 : 0;
  return (mask & number) | (bit << pos);
}
