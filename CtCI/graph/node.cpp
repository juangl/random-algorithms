
#include <vector>
using namespace std;

class Node {
 public:
  typedef vector<Node*> NodeList;

  Node(const char* vertex, int length) : vertex(vertex), adjacentLength(length) {}

  void addAdjecent(Node* x) {
    if (adjacent.size() < adjacentLength) {
      adjacent.push_back(x);
    }
  }

  NodeList getAdjacent() { return adjacent; }

  const char* getVertex() { return vertex; }

  bool getVisited() { return visited; }
  void setVisited(bool val) { visited = val; }

 private:
  NodeList adjacent;
  int adjacentLength;
  const char* vertex;
  bool visited = false;
};
