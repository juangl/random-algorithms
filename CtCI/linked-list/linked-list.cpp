#include <unordered_map>

using namespace std;

template <typename T>
class Node {
 public:
  Node<T>* next = nullptr;
  Node<T>* previous = nullptr;
  T data;
};

template <typename T>
class LinkedListIterator {
 public:
  LinkedListIterator(Node<T>* root) : currentNode(root) {}
  LinkedListIterator<T>& operator++() {
    Node<T>* temp = currentNode;
    currentNode = currentNode->next;
    return currentNode;
  }

  LinkedListIterator<T>& operator--() {
    Node<T>* temp = currentNode;
    currentNode = currentNode->previous;
    return currentNode;
  }

  Node<T>& operator*() { return currentNode; }
  Node<T>& operator->() { return currentNode; }

  bool operator==(LinkedListIterator<T> secondIterator) {
    return secondIterator.currentNode == currentNode;
  }

  bool operator!=(LinkedListIterator<T> secondIterator) {
    return secondIterator.currentNode != currentNode;
  }

 private:
  Node<T>* currentNode;
};

template <typename T>
class LinkedList {
 public:
  Node<T>* root = nullptr;
  typedef LinkedListIterator<T> iterator;
  iterator begin() { return root; }
  iterator end() { return root->previous; }

  Node<T>& head() { return root; }
};
