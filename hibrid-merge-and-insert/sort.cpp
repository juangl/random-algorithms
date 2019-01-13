#include <vector>

using namespace std;

#define K 10

template <class T>
void insertSort(vector<T>& arr, int start, int end) {
  for (int i = 1; i <= end; i++) {
    T current = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

template <class T>
void merge(vector<T>& arr, int start, int middle, int end) {
  int n1 = middle - start + 1;
  int n2 = end - middle;
  int range = end - start;

  vector<T> L = vector<T>(arr.begin() + start, arr.begin() + middle + 1);
  vector<T> R =
      vector<T>(arr.begin() + middle + 1, arr.begin() + end + 1);

  int i = 0, j = 0, k;
  for (int k = 0; k <= range; k++) {
    if (j > n2 || (i < n1 && L[i] < R[j])) {
      arr[start + k] = L[i];
      i++;
    } else {
      arr[start + k] = R[j];
      j++;
    }
  }
}

template <class T>
void hybridSort(vector<T>& arr, int start, int end) {
  if (start + K < end) {
    int middle = (start + end) / 2;
    hybridSort(arr, start, middle);
    hybridSort(arr, middle + 1, end);
    merge(arr, start, middle, end);
  } else {
    insertSort(arr, start, end);
  }
}