#include <cmath>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

bool oneAway(const pair<string, string> wordPair) {
  int counterA = 0;
  int counterB = 0;
  bool mismatchFound = 0;

  int sizeA = wordPair.first.size();
  int sizeB = wordPair.second.size();

  const string& first = sizeA > sizeB ? wordPair.second : wordPair.first;
  const string& second = sizeA > sizeB ? wordPair.first : wordPair.second;

  if (abs(sizeA - sizeB) > 1) {
    return false;
  }

  while (counterA < first.size() && counterB < second.size()) {
    if (first[counterA] != second[counterB]) {
      if (mismatchFound) {
        return false;
      }

      mismatchFound = true;

      if (sizeA == sizeB) {
        ++counterA;
      }
    } else {
      ++counterA;
    }
    ++counterB;
  }

  return true;
}

int main() {
  pair<string, string> words[] = {
      {"pale", "ple"}, {"pales", "pale"}, {"pale", "bale"}, {"pale", "bake"}};

  for (const auto wordPair : words) {
    cout << wordPair.first << ", " << wordPair.second << "  ->  " << boolalpha
         << oneAway(wordPair) << endl;
  }
  return 0;
}
