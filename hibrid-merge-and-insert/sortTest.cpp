#include <cassert>
#include <vector>
#include <iostream>

#include "../utils/isSorted.cpp"
#include "../utils/printVector.cpp"
#include "sort.cpp"

int main() {
    vector<int> arr { 43, 5, 1, 4, 3, 5, 6, 5, 4, 2, 2, 1, 23, 1};
    
    cout << "unsorted:" << endl;
    printVector(arr);

    insertSort(arr, 0, arr.size() - 1);
    assert(isSorted(arr));

    cout << "sorted:" << endl;
    printVector(arr);
    return 0;
}