#include <iostream>
using namespace std;

namespace LinkedList {

template <typename T>
class Node {
 public:
  Node<T>* next = nullptr;
  Node<T>* previous = nullptr;
  T data;
  Node() {}
  Node(T value) : data(value) {}
};

template <typename T>
class LinkedList;

template <typename T>
class LinkedListIterator {
  friend class LinkedList<T>;

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

  T& operator*() { return currentNode->data; }
  T& operator->() { return currentNode->data; }

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
  Node<T>* root;
  typedef LinkedListIterator<T> iterator;

  LinkedList() {
    root = new Node<T>;
    root->next = root;
    root->previous = root;
  }

  ~LinkedList() {
    while (!empty()) {
      remove(begin());
    }

    delete root;
  }

  // iterators
  iterator begin() { return root->next; }
  iterator end() { return root->previous; }

  // values
  Node<T>& head() { return root->next; }
  Node<T>& tail() { return root->previous; }

  // operations
  bool empty() { return root->next == root; }

  void remove(iterator nodeIter) {
    Node<T>* currentNode = nodeIter.currentNode;
    currentNode->next->previous = currentNode->previous;
    currentNode->previous->next = currentNode->next;
    delete currentNode;
    nodeIter.currentNode = nullptr;
  }

  void add(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = root->next;
    root->next->previous = newNode;
    root->next = newNode;
    newNode->previous = root;
  }

  void print() {
    Node<T>* current = root->next;
    while (current != root) {
      cout << current->data << " ";
      current = current->next;
    }
  }
};

}  // namespace LinkedList
