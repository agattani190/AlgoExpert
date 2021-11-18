#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int minNumberOfFrogs(string croakOfFrogs) {
  int n = croakOfFrogs.size();
  if (n % 5) {
    return -1;
  }
  vector<int> freq(5, 0);
  int result = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (croakOfFrogs[i] == 'c') {
      count++;
      freq[0]++;
    } else if (croakOfFrogs[i] == 'k') {
      if (freq[4] == freq[3]) {
        return -1;
      }
      result = max(result, count);
      count--;
      freq[4]++;
    } else if (croakOfFrogs[i] == 'r') {
      if (freq[1] == freq[0]) {
        return -1;
      }
      freq[1]++;
    } else if (croakOfFrogs[i] == 'o') {
      if (freq[2] == freq[1]) {
        return -1;
      }
      freq[2]++;
    } else if (croakOfFrogs[i] == 'a') {
      if (freq[2] == freq[3]) {
        return -1;
      }
      freq[3]++;
    }
  }
  if (freq[0] != n / 5 || freq[1] != freq[0] || freq[2] != freq[0] ||
      freq[3] != freq[0] || freq[4] != freq[0]) {
    return -1;
  }
  return result;
}