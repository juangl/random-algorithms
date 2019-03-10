#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include "../graph/graph.cpp"

using namespace std;

bool search(Graph graph, Node& start, Node& end) {
  queue<Node*> q;
  for (Node* e : graph.getNodes()) {
    e->setVisited(false);
  }
  q.push(&start);
  start.setVisited(true);

  while (q.size() > 0) {
    Node& currentNode = *(q.front());
    q.pop();

    if (strcmp(currentNode.getVertex(), end.getVertex()) == 0) {
      return true;
    }

    for (Node* e : currentNode.getAdjacent()) {
      if (!e->getVisited()) {
        q.push(e);
        currentNode.setVisited(true);
      }
    }
  }

  return false;
}

int main() {
  Graph graph;
  vector<Node> nodes{Node("a", 2), Node("b", 1), Node("c", 0),
                     Node("d", 0), Node("e", 2), Node("f", 0)};

  nodes[0].addAdjecent(&nodes[1]);
  nodes[0].addAdjecent(&nodes[2]);
  nodes[1].addAdjecent(&nodes[3]);
  nodes[4].addAdjecent(&nodes[0]);
  nodes[4].addAdjecent(&nodes[1]);

  for (Node& e : nodes) {
    graph.addNode(&e);
  }

  cout << "search from a to f:" << endl;
  cout << boolalpha << search(graph, nodes[0], nodes[5]);
  cout << "\n\nsearch from a to d:" << endl;
  cout << search(graph, nodes[0], nodes[3]);
  return 0;
}
