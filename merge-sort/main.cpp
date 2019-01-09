#include <iostream>

using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1];
    int R[n2];

    int i, j;
    for (i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    i = 0;
    j = 0;

    for (int k = p; k <= r; k++) {
        if (j >= n2 || (i < n1 && L[i] < R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int q) {
    if (q > p) {
        int middle = (p + q) / 2;
        mergeSort(arr, p, middle);
        mergeSort(arr, middle + 1, q);
        merge(arr, p, middle, q);
    }
}

int main() {
    int arr[] = {20, 18, 16, 14, 10, 8, 1, 5, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "items before order:\n";
    printArr(arr, size);
    cout << "\n\n";

    cout << "items after order:\n";
    mergeSort(arr, 0, size - 1);
    
    printArr(arr, size);
    cout << "\n\n";

    return 0;
}
