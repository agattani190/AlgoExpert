#include <stack>
#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sunsetViews(vector<int> buildings, string direction) {
  vector<int> result;
  stack<int> st;
  int n = buildings.size();
  if (direction == "EAST") {
    for (int i = n - 1; i >= 0; i--) {
      if (st.empty() || st.top() < buildings[i]) {
        result.push_back(i);
        st.push(buildings[i]);
      }
    }
    int resultSize = result.size();
    for (int i = 0; i < resultSize / 2; i++) {
      swap(result[i], result[resultSize - i - 1]);
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (st.empty() || st.top() < buildings[i]) {
        result.push_back(i);
        st.push(buildings[i]);
      }
    }
  }
  return result;
}
