#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

bool checkLength(const pair<string, string>& stringPair) {
  return stringPair.first.size() == stringPair.second.size();
}

bool isPermutationHasTable(const pair<string, string>& stringPair) {
  if (!checkLength(stringPair)) {
    return false;
  }

  unordered_map<char, int> presentCharsA;
  unordered_map<char, int> presentCharsB;

  for (int i = 0; i < stringPair.first.size(); i++) {
    char charA = stringPair.first[i];
    char charB = stringPair.second[i];

    unordered_map<char, int>::const_iterator gotA = presentCharsA.find(charA);
    unordered_map<char, int>::const_iterator gotB = presentCharsB.find(charB);

    int countA = gotA == presentCharsA.end() ? 1 : gotA->second + 1;
    int countB = gotB == presentCharsB.end() ? 1 : gotB->second + 1;

    presentCharsA.insert({charA, countA});
    presentCharsB.insert({charB, countB});
  }
 
  for (auto& u : presentCharsA) {
    unordered_map<char, int>::const_iterator got = presentCharsB.find(u.first);

    if (got == presentCharsB.end() || got->second != u.second) {
      return false;
    }
  }

  return true;
}

bool isPermutationSorting(pair<string, string>& stringPair) {
  if (!checkLength(stringPair)) {
    return false;
  }
  sort(stringPair.first.begin(), stringPair.first.end());
  sort(stringPair.second.begin(), stringPair.second.end());

  for (int i = 0; i < stringPair.first.size(); i++) {
    if (stringPair.first[i] != stringPair.second[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<pair<string, string>> stringPairs = {{"asdf", "fdsa"},
                                              {"this isn't", "this either"},
                                              {"1234", "2134"},
                                              {"asdf", "fdsaa"}};

  for (auto& currentPair : stringPairs) {
    cout << "word 1:" << currentPair.first << " word 2: " << currentPair.second
         << endl;
    cout << "test with hash table: " << boolalpha
         << isPermutationHasTable(currentPair) << endl;
    // sorting is the last because it mutates
    cout << "test with sorting: " << boolalpha
         << isPermutationSorting(currentPair) << "\n\n"
         << endl;
  }
  return 0;
}
