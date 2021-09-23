#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int maxSatisfaction(vector<int> &satisfaction) {
  int n = satisfaction.size();
  if (n == 1) {
    return max(satisfaction[0], 0);
  }
  sort(satisfaction.begin(), satisfaction.end());
  if (satisfaction[n - 1] < 1) {
    return 0;
  }
  vector<int> prevSum(n);
  prevSum[0] = satisfaction[0];
  int result = prevSum[0];
  for (int i = 1; i < n; i++) {
    result += (satisfaction[i] * (i + 1));
    prevSum[i] = satisfaction[i] + prevSum[i - 1];
  }
  if (satisfaction[0] > -1) {
    return result;
  }
  result = max(result, result - prevSum[n - 1]);
  for (int i = 1; i < n; i++) {
    result = max(result, result - prevSum[n - 1] + prevSum[i - 1]);
  }
  return result;
}