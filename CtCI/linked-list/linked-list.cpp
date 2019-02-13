#include <unordered_map>

using namespace std;

template <typename T>
class Node {
 public:
  Node<T>* next = nullptr;
  Node<T>* previous = nullptr;
  T data;
  Node(T value) : data(value) {}
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
  friend class LinkedListIterator<T>;

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
      remove(head());
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
  bool empty() { return root->head == root; }

  void remove(iterator nodeIter) {
    nodeIter.next.previus = nodeIter.currentNode.previous;
    nodeIter.previous.next = nodeIter.currentNode.next;
    delete nodeIter.currentNode;
    nodeIter.currentNode = nullptr;
  }

  void add(T value) {
    Node<T> newNode = new Node<T>(value);
    root->next->previous = newNode;
    root->next = newNode;
  }
};
