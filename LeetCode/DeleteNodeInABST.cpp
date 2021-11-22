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

// Time Complexity: O(h) - h is the height of the tree
// Space Complexity: O(h)
TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root) {
    return root;
  }
  if (root->val > key) {
    root->left = deleteNode(root->left, key);
  } else if (root->val < key) {
    root->right = deleteNode(root->right, key);
  } else if (!root->left && !root->right) {
    return NULL;
  } else if (root->right) {
    TreeNode *temp = root->right;
    while (temp->left) {
      temp = temp->left;
    }
    root->val = temp->val;
    root->right = deleteNode(root->right, temp->val);
  } else {
    TreeNode *temp = root->left;
    while (temp->right) {
      temp = temp->right;
    }
    root->val = temp->val;
    root->left = deleteNode(root->left, temp->val);
  }
  return root;
}