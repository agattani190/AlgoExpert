#include <queue>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) { val = _val; }
  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

// Time Complexity: O(n) -> n is the number of nodes in the tree
// Space Complexity: O(n)
vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> result;
  if (!root) {
    return result;
  }
  vector<int> temp;
  queue<Node *> q;
  q.push(root);
  int sz;
  Node *curr;
  while (!q.empty()) {
    sz = q.size();
    while (sz--) {
      curr = q.front();
      q.pop();
      for (int i = 0; i < curr->children.size(); i++) {
        q.push(curr->children[i]);
      }
      temp.push_back(curr->val);
    }
    result.push_back(temp);
    temp = {};
  }
  return result;
}