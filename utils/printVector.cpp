#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << endl;
}
