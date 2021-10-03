#include <vector>
using namespace std;

class RLEIterator {
public:
  long long int index = 0;
  vector<int> arr;
  vector<long long int> count;

  // Time Complexity: O(n)
  // Space Complexity: O(n)
  RLEIterator(vector<int> &encoding) {
    int n = encoding.size();
    arr.push_back(encoding[1]);
    count.push_back(encoding[0]);
    for (int i = 2; i < n; i += 2) {
      arr.push_back(encoding[i + 1]);
      count.push_back(*(count.end() - 1) + encoding[i]);
    }
  }

  // Time Complexity: O(logn)
  // Space Complexity: O(1)
  int next(int n) {
    index += n;
    auto lowerBound = lower_bound(count.begin(), count.end(), index);
    if (lowerBound == count.end()) {
      return -1;
    }
    return arr[lowerBound - count.begin()];
  }
};