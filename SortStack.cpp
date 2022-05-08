#include <vector>
using namespace std;

void insertInSortedStack(vector<int> &stack, int top) {
  if (stack.size() == 0 || top >= stack.back()) {
    stack.push_back(top);
  } else {
    int newTop = stack.back();
    stack.pop_back();
    insertInSortedStack(stack, top);
    stack.push_back(newTop);
  }
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<int> sortStack(vector<int> &stack) {
  int n = stack.size();
  if (n < 2) {
    return stack;
  }
  int top = stack.back();
  stack.pop_back();
  sortStack(stack);
  insertInSortedStack(stack, top);
  return stack;
}
