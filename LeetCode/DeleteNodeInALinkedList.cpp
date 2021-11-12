#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(1)
// Space Complexity: O(1)
void deleteNode(ListNode *node) {
  ListNode *temp = node->next;
  node->val = temp->val;
  node->next = temp->next;
  delete temp;
}