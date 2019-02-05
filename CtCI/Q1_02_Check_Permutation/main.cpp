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

  unordered_map<char, bool> presentChars;

  for (const char& e : stringPair.first) {
    presentChars.insert({e, true});
  }

  for (const char& u : stringPair.second) {
    unordered_map<char, bool>::const_iterator got = presentChars.find(u);

    if (got == presentChars.end()) {
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
    // this implementation requires that all the characters are unique
    cout << "test with hash table: " << boolalpha
         << isPermutationHasTable(currentPair) << endl;
    // sorting is the last because it mutates
    cout << "test with sorting: " << boolalpha
         << isPermutationSorting(currentPair) << "\n\n"
         << endl;
  }
  return 0;
}
