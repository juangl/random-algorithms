#include <iostream>
#include <random>
#include <functional>
#include <vector>
#include <cassert>

#include "../utils/printVector.cpp"
#include "../utils/isSorted.cpp"
#include "sort.cpp"

using namespace std;

#define SIZE 10000

int main() {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, SIZE);
    auto dice = std::bind(distribution, generator);

    vector<int> numbers(SIZE);

    for (int &e : numbers) {
        e = dice();
    }

    cout << "unsorted:" << endl;
    printVector(numbers);

    hybridSort(numbers, 0, SIZE - 1);

    assert(isSorted(numbers));
    assert(numbers.size() == SIZE);

    cout << "sorted:" << endl;
    printVector(numbers);
    return 0;
}
