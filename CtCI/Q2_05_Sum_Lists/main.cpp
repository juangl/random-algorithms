#include <iostream>

using namespace std;

#include "../../utils/printVector.cpp"
#include "../linked-list/linked-list.cpp"

void addSum(LinkedList<int>& result, int sum) {
  int units = sum % 10;
  int tens = sum / 10;
  result.head() += units;
  result.push_front(tens);
}

LinkedList<int> sumList(LinkedList<int>& op1, LinkedList<int>& op2) {
  LinkedList<int> result = {0};

  LinkedList<int>::iterator iter1 = op1.begin();
  LinkedList<int>::iterator iter2 = op2.begin();

  while (iter1 != op1.end() && iter2 != op2.end()) {
    int sum = *iter1 + *iter2;
    addSum(result, sum);
    iter1++;
    iter2++;
  }

  LinkedList<int>::iterator* remainding = nullptr;
  LinkedList<int>::iterator end;
  if (iter1 != op1.end()) {
    remainding = &iter1;
    end = op1.end();
  } else if (iter2 != op2.end()) {
    remainding = &iter2;
    end = op2.end();
  }

  if (remainding) {
    while (*remainding != end) {
      addSum(result, **remainding);
      ++(*remainding);
    }
  }

  if (result.head() == 0) {
    result.remove_front();
  }
  return result;
}

int main() {
  LinkedList<int> sum1[] = {{2, 7, 2}, {4, 9, 2}};

  LinkedList<int> result1 = sumList(sum1[0], sum1[1]);

  cout << "operator 1:" << endl;
  printIter(sum1[0]);
  cout << "operator 2:" << endl;
  printIter(sum1[1]);
  cout << "result:" << endl;
  printIter(result1);
  return 0;
}
