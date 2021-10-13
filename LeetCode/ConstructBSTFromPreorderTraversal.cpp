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

TreeNode *bstFromPreorderHelper(vector<int> &preorder, int leftPtr,
                                int rightPtr);

// Time Complexity: O(n^2)
// Space Complexity: O(n)
TreeNode *bstFromPreorder(vector<int> &preorder) {
  int n = preorder.size();
  return bstFromPreorderHelper(preorder, 0, n - 1);
}

TreeNode *bstFromPreorderHelper(vector<int> &preorder, int leftPtr,
                                int rightPtr) {
  if (leftPtr <= rightPtr) {
    int temp = leftPtr;
    TreeNode *head = new TreeNode(preorder[leftPtr]);
    while (leftPtr <= rightPtr && preorder[leftPtr] <= head->val) {
      leftPtr++;
    }
    if (leftPtr != temp) {
      head->left = bstFromPreorderHelper(preorder, temp + 1, leftPtr - 1);
    }
    head->right = bstFromPreorderHelper(preorder, leftPtr, rightPtr);
    return head;
  }
  return NULL;
}