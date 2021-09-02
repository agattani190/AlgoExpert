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
ListNode *middleNode(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
    if (fast) {
      fast = fast->next;
    }
  }
  return slow;
}