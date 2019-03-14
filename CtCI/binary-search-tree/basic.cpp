struct Node {
  int val;
  Node* left;
  Node* right;
};

Node* createNewNode(int x) {
  Node* nn = new Node;
  nn->val = x;
  nn->left = nullptr;
  nn->right = nullptr;

  return nn;
}

void bstInsert(Node* root, int x) {
  if (root == nullptr) {
    root = createNewNode(x);
    return;
  }

  if (x <= root->val) {
    if (root->left == nullptr) {
      root->left = createNewNode(x);
      return;
    } else {
      bstInsert(root->left, x);
    }
  }

  if (x > root->val) {
    if (root->right == nullptr) {
      root->right = createNewNode(x);
      return;
    } else {
      bstInsert(root->right, x);
    }
  }
}
