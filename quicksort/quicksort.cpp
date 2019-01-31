#include <vector>
using namespace std;

template <typename T>
int partition(vector<T>& A, int start, int end) {
  T x = A[end];
  int j = start - 1;
  for (int i = start; i < end; i++) {
    if (A[i] < x) {
      j++;
      swap(A[j], A[i]);
    }
  }
  swap(A[j + 1], A[end]);
  return j + 1;
}

template <typename T>
void quickSort(vector<T>& A, int start, int end) {
  if (start < end) {
    int partitionIndex = partition(A, start, end);
    quickSort(A, start, partitionIndex - 1);
    quickSort(A, partitionIndex + 1, end);
  }
}