#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

unordered_map<TreeNode *, int> mp;

// Average Time Complexity: O(n) -> Number of nodes in the tree
// Space Complexity: O(n)
int rob(TreeNode *root) {
  if (!root) {
    return 0;
  }
  if (mp.find(root) != mp.end()) {
    return mp[root];
  }
  int x = root->val;
  if (root->left) {
    x += rob(root->left->left);
    x += rob(root->left->right);
  }
  if (root->right) {
    x += rob(root->right->left);
    x += rob(root->right->right);
  }
  mp[root] = max(x, rob(root->left) + rob(root->right));
  return mp[root];
}