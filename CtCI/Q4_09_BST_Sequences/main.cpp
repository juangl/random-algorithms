
#include <iostream>
#include <list>
#include <vector>

#include "../binary-search-tree/basic.cpp"

using namespace std;

vector<vector<int>> getBSTSequences(vector<Node*>& availableNodes,
                                    vector<int>& prefixPath) {
  if (availableNodes.size() == 0) {
    return {prefixPath};
  }

  vector<vector<int>> fullList;
  for (int i = 0; i < availableNodes.size(); i++) {
    vector<Node*> nextAvailableNodes;
    nextAvailableNodes.reserve(availableNodes.size() + 1);
    vector<int> newPrefix;
    newPrefix.reserve(prefixPath.size() + 1);
    newPrefix = prefixPath;

    for (int j = 0; j < availableNodes.size(); j++) {
      // copying all values except the current one
      if (j != i) {
        nextAvailableNodes.push_back(availableNodes[j]);
      }
    }

    Node* currentNode = availableNodes[i];

    if (currentNode->left != nullptr) {
      nextAvailableNodes.push_back(currentNode->left);
    }

    if (currentNode->right != nullptr) {
      nextAvailableNodes.push_back(currentNode->right);
    }

    newPrefix.push_back(currentNode->val);

    vector<vector<int>> currentList =
        getBSTSequences(nextAvailableNodes, newPrefix);
    fullList.insert(fullList.end(), currentList.begin(), currentList.end());
  }

  return fullList;
}

int main() {
  Node* root = createNewNode(4);
  bstInsert(root, 2);
  bstInsert(root, 6);
  bstInsert(root, 1);
  bstInsert(root, 3);
  bstInsert(root, 5);
  bstInsert(root, 7);

  vector<Node*> rootList{root};
  vector<int> prefixPath;
  vector<vector<int>> sequences = getBSTSequences(rootList, prefixPath);

  for (auto e : sequences) {
    for (int current : e) {
      cout << current << " ";
    }
    cout << endl;
  }
  return 0;
}
