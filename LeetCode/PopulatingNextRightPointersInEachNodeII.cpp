#include <queue>
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
  if (!root) {
    return root;
  }
  queue<Node *> q;
  q.push(root);
  int size;
  Node *curr;
  while (!q.empty()) {
    size = q.size();
    while (size--) {
      curr = q.front();
      q.pop();
      if (size) {
        curr->next = q.front();
      }
      if (curr->left) {
        q.push(curr->left);
      }
      if (curr->right) {
        q.push(curr->right);
      }
    }
  }
  return root;
}