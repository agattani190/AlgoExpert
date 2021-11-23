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
  Node *temp;
  int sz;
  while (!q.empty()) {
    sz = q.size();
    while (sz--) {
      temp = q.front();
      q.pop();
      if (sz != 0) {
        temp->next = q.front();
      }
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
  return root;
}