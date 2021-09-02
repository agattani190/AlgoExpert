#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(k) -> k is the size of the linked list
// Space Complexity: O(1)
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (n--) {
    fast = fast->next;
  }
  if (fast == nullptr) {
    return head->next;
  }
  while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }
  ListNode *nodeToDelete = slow->next;
  slow->next = slow->next->next;
  nodeToDelete->next = nullptr;
  return head;
}