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
ListNode *oddEvenList(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode *temp = head->next;
  ListNode *odd = head;
  ListNode *even = temp;
  while (even) {
    odd->next = even->next;
    if (!odd->next) {
      break;
    }
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = temp;
  return head;
}