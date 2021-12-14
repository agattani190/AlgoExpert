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

int rangeSumBSTHelper(TreeNode *root, int low, int high, int sum);

// Time Complexity: O(n) - n is number of nodes in the tree
// Space Complexity: O(n)
int rangeSumBST(TreeNode *root, int low, int high) {
  return rangeSumBSTHelper(root, low, high, 0);
}

int rangeSumBSTHelper(TreeNode *root, int low, int high, int sum) {
  if (!root) {
    return sum;
  }
  if (root->val >= low && root->val <= high) {
    sum += root->val;
  }
  if (root->left && root->val > low) {
    sum = rangeSumBSTHelper(root->left, low, high, sum);
  }
  if (root->right && root->val < high) {
    sum = rangeSumBSTHelper(root->right, low, high, sum);
  }
  return sum;
}