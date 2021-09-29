#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(n) -> n is the num of nodes in the linked list
// Space Complexity: O(1)
vector<ListNode *> splitListToParts(ListNode *head, int k) {
  ListNode *temp = head;
  int count = 0;
  while (temp) {
    count++;
    temp = temp->next;
  }
  int numInEachPart = count / k;
  int extraNumParts = count % k;
  vector<ListNode *> result(k);
  temp = head;
  ListNode *prev = nullptr;
  for (int i = 0; i < k; i++) {
    count = numInEachPart;
    if (extraNumParts > 0) {
      count++;
      extraNumParts--;
    }
    if (count > 0) {
      if (prev) {
        prev->next = nullptr;
      }
      result[i] = temp;
      while (count--) {
        prev = temp;
        temp = temp->next;
      }
    }
  }
  return result;
}