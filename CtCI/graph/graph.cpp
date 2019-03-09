#include <iostream>
#include "node.cpp"

using namespace std;

const int MAX_VERTICES = 6;

class Graph {
 public:
  Graph() {}

  void addNode(Node* x) {
    if (count < MAX_VERTICES) {
      vertices[count] = x;
      count++;
    } else {
      cerr << "Graph full";
    }
  }
 private:
  Node* vertices[MAX_VERTICES];
  int count = 0;
};
