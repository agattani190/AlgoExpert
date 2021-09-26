#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> maxPathSumhelper(BinaryTree *tree);

// Time Complexity: O(n) - n is number of nodes in the tree
// Space Complexity: O(n)
int maxPathSum(BinaryTree tree) { return maxPathSumhelper(&tree)[0]; }

vector<int> maxPathSumhelper(BinaryTree *tree) {
  if (!tree) {
    return {INT_MIN, 0};
  }
  vector<int> l = maxPathSumhelper(tree->left);
  vector<int> r = maxPathSumhelper(tree->right);
  vector<int> res(2, INT_MIN);
  res[1] = max(tree->value + max(l[1], r[1]), tree->value);
  res[0] = max(max(max(l[0], r[0]), l[1] + r[1] + tree->value), res[1]);
  return res;
}