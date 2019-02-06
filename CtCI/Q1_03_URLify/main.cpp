#include <iostream>
#include <string>

using namespace std;

void URLify(string& url, int size) {
  int newStrSize = url.size();
  int newStrPos = newStrSize - 1;
  int originalStrPos = size - 1;

  while(originalStrPos >= 0) {
    if (url[originalStrPos] == ' ') {
      url.replace(newStrPos - 2, 3, "%20");
      newStrPos -= 3;
    } else {
      url[newStrPos] = url[originalStrPos];
      newStrPos -= 1;
    }
    originalStrPos -= 1;
  }
}

struct Input {
  string url;
  int size;
};

int main() {
  Input urls[] = {{"test number one    ", 15}, {"some other test    ", 15}};

  for (auto& input : urls) {
    cout << "before: " << input.url << endl;
    URLify(input.url, input.size);

    cout << "after: " << input.url << endl;
    cout << "\n\n";
  }
  return 0;
}
