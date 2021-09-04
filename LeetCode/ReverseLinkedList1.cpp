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
ListNode *reverseList(ListNode *head) {
  if (!head || !head->next) {
    return head;
  }
  ListNode *reversedLinkedListHead = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return reversedLinkedListHead;
}