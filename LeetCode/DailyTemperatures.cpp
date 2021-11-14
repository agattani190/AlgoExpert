#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> dailyTemperatures(vector<int> &temperatures) {
  int n = temperatures.size();
  vector<int> answers(n, 0);
  stack<int> s;
  s.push(n - 1);
  for (int i = n - 2; i >= 0; i--) {
    while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
      s.pop();
    }
    if (!s.empty()) {
      answers[i] = s.top() - i;
    }
    s.push(i);
  }
  return answers;
}