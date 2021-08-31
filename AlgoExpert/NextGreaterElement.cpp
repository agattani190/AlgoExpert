#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> nextGreaterElement(vector<int> array) {
  int arraySize = array.size();
  vector<int> result(arraySize);
  stack<int> st;
  int index = 0;
  while (true) {
    while (!st.empty() && array[st.top()] < array[index]) {
      result[st.top()] = array[index];
      st.pop();
    }
    if (!st.empty() && st.top() == index || st.size() == arraySize) {
      break;
    }
    st.push(index);
    index = (index + 1) % arraySize;
  }
  while (!st.empty()) {
    result[st.top()] = -1;
    st.pop();
  }
  return result;
}
