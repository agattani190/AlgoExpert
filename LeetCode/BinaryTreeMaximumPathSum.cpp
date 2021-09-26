#include <vector>
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

vector<int> maxPathSumhelper(TreeNode *root);

// Time Complexity: O(n) - n is number of nodes in the tree
// Space Complexity: O(n)
int maxPathSum(TreeNode *root) { return maxPathSumhelper(root)[0]; }

vector<int> maxPathSumhelper(TreeNode *root) {
  if (!root) {
    return {INT_MIN, 0};
  }
  vector<int> l = maxPathSumhelper(root->left);
  vector<int> r = maxPathSumhelper(root->right);
  vector<int> res(2, INT_MIN);
  res[1] = max(root->val + max(l[1], r[1]), root->val);
  res[0] = max(max(max(l[0], r[0]), l[1] + r[1] + root->val), res[1]);
  return res;
}