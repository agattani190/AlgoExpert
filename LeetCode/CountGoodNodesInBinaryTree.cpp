#include <iostream>
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

int goodNodesHelper(TreeNode *root, int currMax);

// Time Complexity: O(n) -> n is the minimum number of nodes in the two trees
// Space Complexity: O(n)
int goodNodes(TreeNode *root) { return (goodNodesHelper(root, INT_MIN)); }

int goodNodesHelper(TreeNode *root, int currMax) {
  int result = 0;
  if (!root) {
    return 0;
  }
  if (root->val >= currMax) {
    currMax = root->val;
    result++;
  }
  return result + goodNodesHelper(root->left, currMax) +
         goodNodesHelper(root->right, currMax);
}