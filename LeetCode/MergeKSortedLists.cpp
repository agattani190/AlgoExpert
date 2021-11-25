#include <queue>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(Nlogk) - N is total number of nodes
// Space Complexity: O(k)
ListNode *mergeKLists(vector<ListNode *> &lists) {
  int k = lists.size();
  priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>,
                 greater<pair<int, ListNode *>>>
      pq;
  for (int i = 0; i < k; i++) {
    if (lists[i]) {
      pq.push({lists[i]->val, lists[i]});
    }
  }
  ListNode *head = new ListNode(0);
  ListNode *result = head;
  ListNode *temp;
  while (!pq.empty()) {
    temp = pq.top().second;
    pq.pop();
    if (temp->next) {
      pq.push({temp->next->val, temp->next});
    }
    head->next = temp;
    head = head->next;
  }
  return result->next;
}