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

int diameter;

int diameterOfBinaryTreeHelper(TreeNode *root);

// Time Complexity: O(n) - n is number of nodes in the tree
// Space Complexity: O(n)
int diameterOfBinaryTree(TreeNode *root) {
  diameter = 0;
  diameterOfBinaryTreeHelper(root);
  return diameter;
}

int diameterOfBinaryTreeHelper(TreeNode *root) {
  if (!root) {
    return 0;
  }
  int l = diameterOfBinaryTreeHelper(root->left);
  int r = diameterOfBinaryTreeHelper(root->right);
  diameter = max(l + r, diameter);
  return max(l, r) + 1;
}