#include <initializer_list>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList;

namespace LinkedListUtils {
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

}  // namespace LinkedListUtils

template <typename T>
class LinkedList {
 public:
  typedef LinkedListUtils::Node<T> Node;
  typedef LinkedListUtils::LinkedListIterator<T> iterator;
  Node* root;

  LinkedList() {
    root = new Node;
    root->next = root;
    root->previous = root;
  }

  LinkedList(const initializer_list<T>& init) : LinkedList() {
    for (auto& e : init) {
      add(e);
    }
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
  Node& head() { return root->next; }
  Node& tail() { return root->previous; }

  // operations
  bool empty() { return root->next == root; }

  void remove(iterator nodeIter) {
    Node* currentNode = nodeIter.currentNode;
    currentNode->next->previous = currentNode->previous;
    currentNode->previous->next = currentNode->next;
    delete currentNode;
    nodeIter.currentNode = nullptr;
  }

  void add(T value) {
    Node* newNode = new Node(value);
    newNode->next = root->next;
    root->next->previous = newNode;
    root->next = newNode;
    newNode->previous = root;
  }

  void print() {
    Node* current = root->next;
    while (current != root) {
      cout << current->data << " ";
      current = current->next;
    }
  }
};
