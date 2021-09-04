#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseLinkedList(ListNode *head) {
  ListNode *prev, *curr, *next;
  prev = nullptr;
  curr = head;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

ListNode *getMiddleNode(ListNode *head) {
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

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isPalindrome(ListNode *head) {
  ListNode *middleNode = getMiddleNode(head);
  ListNode *reversedListHead = reverseLinkedList(middleNode);
  while (head && reversedListHead) {
    if (head->val != reversedListHead->val) {
      return false;
    }
    head = head->next;
    reversedListHead = reversedListHead->next;
  }
  return true;
}