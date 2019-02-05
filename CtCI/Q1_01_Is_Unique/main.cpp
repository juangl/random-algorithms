#include <bitset>
#include <iostream>
#include <string>

using namespace std;

bool uniqueCharsNoDS(const char* str) {
  bool chars[254] = {false};

  char currentChar;
  while ((currentChar = *(str)) != '\0') {
    if (chars[currentChar]) {
      return false;
    }

    chars[currentChar] = true;
    str++;
  }

  return true;
}

bool uniqueCharsBitset(const char* str) {
  bitset <254> unique = 0;
  char currentChar;
  while ((currentChar = *(str)) != '\0') {
    if (unique[currentChar]) {
      return false;
    }

    unique.flip(currentChar);
    str++;
  }
  return true;
}

int main() {
  const char* const strs[] = {"uniq chars", "no unique", "no unique either"};

  cout << "without additional data structures: " << endl;
  for (auto e : strs) {
    cout << e << ": " << boolalpha << uniqueCharsNoDS(e) << endl;
  }



  cout << "\n\nwith bitset: " << endl;
  for (auto e : strs) {
    cout << e << ": " << boolalpha << uniqueCharsNoDS(e) << endl;
  }
  return 0;
}
