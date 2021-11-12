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
// Space Complexity: O(n)
ListNode *removeElements(ListNode *head, int val) {
  if (!head) {
    return head;
  }
  if (head->val == val) {
    return removeElements(head->next, val);
  }
  head->next = removeElements(head->next, val);
  return head;
}