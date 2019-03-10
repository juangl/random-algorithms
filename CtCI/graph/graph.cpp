#include <iostream>
#include <vector>
#include "node.cpp"

using namespace std;

const int MAX_VERTICES = 6;

class Graph {
 public:
  typedef vector<Node*> NodeList;
  Graph() : vertices(MAX_VERTICES) {}

  void addNode(Node* x) {
    if (count < MAX_VERTICES) {
      vertices[count] = x;
      count++;
    } else {
      cerr << "Graph full";
    }
  }

  NodeList getNodes() { return vertices; }

 private:
  NodeList vertices;
  int count = 0;
};
