#include <algorithm>
#include <vector>

using namespace std;

template <class T>
bool isSorted(vector<T> arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }

  return true;
}