#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// Time Complexity: O(n)
// Space Complexity: O(n)
Node *connect(Node *root) {
  if (root && root->left && root->right) {
    root->left->next = root->right;
    if (root->next) {
      root->right->next = root->next->left;
    }
    root->left = connect(root->left);
    root->right = connect(root->right);
  }
  return root;
}