#include <stack>
#include <vector>
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
vector<int> nextLargerNodes(ListNode *head) {
  vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  int n = result.size();
  stack<int> s;
  int temp;
  for (int i = n - 1; i >= 0; i--) {
    temp = result[i];
    while (!s.empty() && s.top() <= temp) {
      s.pop();
    }
    if (s.empty()) {
      result[i] = 0;
    } else {
      result[i] = s.top();
    }
    s.push(temp);
  }
  return result;
}