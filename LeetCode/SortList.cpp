#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeList(ListNode *left, ListNode *right);

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
ListNode *sortList(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast) {
    fast = fast->next;
    if (fast) {
      fast = fast->next;
      slow = slow->next;
    }
  }
  ListNode *mid = slow->next;
  slow->next = NULL;
  ListNode *left = sortList(head);
  ListNode *right = sortList(mid);
  return mergeList(left, right);
}

ListNode *mergeList(ListNode *left, ListNode *right) {
  if (!left) {
    return right;
  }
  if (!right) {
    return left;
  }
  if (left->val <= right->val) {
    left->next = mergeList(left->next, right);
    return left;
  }
  right->next = mergeList(left, right->next);
  return right;
}