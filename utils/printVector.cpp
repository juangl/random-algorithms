#include <iostream>

using namespace std;

template <class T>
void printVector(T& vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << endl;
}
