class Node {
 public:
  Node() : adjacentCount(0) {}
  Node(const char* vertex, int adjacentLength)
      : vertex(vertex), adjacentCount(0), adjacentLength(adjacentLength) {
    adjacent = new Node* [adjacentLength] { nullptr };
  }

  ~Node() { delete[] adjacent; }

  void addAdjecent(Node* x) {
    if (adjacentCount < adjacentLength) {
      adjacent[adjacentCount] = x;
      adjacentCount++;
    }
  }

  Node** getAdjacent() { return adjacent; }

  const char* getVertex() { return vertex; }

 private:
  Node** adjacent;
  int adjacentCount;
  int adjacentLength;
  const char* vertex;
};
