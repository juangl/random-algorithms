#include <iostream>
#include <utility>
using namespace std;

#include "../linked-list/linked-list.cpp"

typedef LinkedList<int> IntLinkedList;

void partition(IntLinkedList& list, int x) {
  IntLinkedList::iterator nextInsertion = list.begin();

  while (*nextInsertion < x && nextInsertion != list.end()) {
    ++nextInsertion;
  }

  IntLinkedList::iterator current = nextInsertion;
  ++current;
  while (current != list.end()) {
    if (*current < x) {
      iter_swap(current, nextInsertion);
      nextInsertion++;
    }
    current++;
  }
}

int main() {
  IntLinkedList list{3, 5, 8, 5, 10, 2, 1};

  list.print();

  cout << "\n\n";

  partition(list, 5);

  list.print();
  return 0;
}
