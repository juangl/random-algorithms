#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include "utils.cpp"

uint32_t getNext(uint32_t number) {
  queue<int> available0s;
  for (int i = 0; i < 31; i++) {
    bool currentPos = testPosRight(number, i);
    bool nextPos = testPosRight(number, i + 1);
    if (currentPos && !nextPos) {
      number = setBitRight(number, i, false);
      number = setBitRight(number, i + 1, true);
      break;
    } else if (!currentPos) {
      available0s.push(currentPos);
    } else if (currentPos && !available0s.empty()) {
      int exchangePos = available0s.front();
      available0s.pop();

      number = setBitRight(number, i, false);
      number = setBitRight(number, exchangePos, true);
      available0s.push(i);
    }
  }

  return number;
}

uint32_t getPrevious(uint32_t number) {
  // WIP
  return number;
}

int main() {
  vector<uint32_t> numbers{41, 42, 38};

  cout << setw(10) << "number" << setw(10) << "next" << setw(10) << "previous"
       << endl;

  for (int i = 0; i < numbers.size(); i++) {
    cout << setw(10) << numbers[i] << setw(10) << getNext(numbers[i])
         << setw(10) << getPrevious(numbers[i]) << endl;
  }
  return 0;
}
