#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(m + n) - m and n are the number of nedes in the two lists
// Space Complexity: O(1)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *result = l1;
  ListNode *prev;
  int carry = 0;
  int sum;
  while (l1 && l2) {
    prev = l1;
    sum = l1->val + l2->val + carry;
    l1->val = sum % 10;
    carry = sum / 10;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    prev = l1;
    sum = l1->val + carry;
    l1->val = sum % 10;
    carry = sum / 10;
    l1 = l1->next;
  }
  if (l2) {
    prev->next = l2;
  }
  while (l2) {
    prev = l2;
    sum = l2->val + carry;
    l2->val = sum % 10;
    carry = sum / 10;
    l2 = l2->next;
  }
  if (carry) {
    prev->next = new ListNode(carry);
  }
  return result;
}