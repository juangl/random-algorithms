#include <bitset>
#include <iostream>
#include <string>

using namespace std;

bool uniqueCharsNoDS(const char* str) {
  bool chars[254] = {false};

  char currentChar;
  int offset = 0;
  while ((currentChar = *(str + offset)) != '\0') {
    if (chars[currentChar]) {
      return false;
    }

    chars[currentChar] = true;
    offset++;
  }

  return true;
}

int main() {
  const char* const strs[3] = {"uniq chars", "no unique", "no unique either"};

  cout << "without additional data structures: " << endl;
  for (int i = 0; i < 3; i++) {
    cout << strs[i] << ": " << boolalpha << uniqueCharsNoDS(strs[i]) << endl;
  }
  return 0;
}
