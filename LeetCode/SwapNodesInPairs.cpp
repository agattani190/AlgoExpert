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
ListNode *swapPairs(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }

  ListNode *temp = swapPairs(head->next->next);
  ListNode *res = head->next;
  head->next = temp;
  res->next = head;
  return res;
}