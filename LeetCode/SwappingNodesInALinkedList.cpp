#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode *swapNodes(ListNode *head, int k) {
  int n = 1;
  ListNode *temp = head;
  ListNode *a = NULL;
  ListNode *b = NULL;
  while (temp) {
    if (b) {
      b = b->next;
    }
    if (n == k) {
      a = temp;
      b = head;
    }
    temp = temp->next;
    n++;
  }
  swap(a->val, b->val);
  return head;
}