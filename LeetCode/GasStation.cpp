#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int n = gas.size();
  int prevGas = 0;
  int extraGasRequired = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (prevGas + gas[i] < cost[i]) {
      extraGasRequired += (cost[i] - prevGas - gas[i]);
      prevGas = 0;
      result = i + 1;
    } else {
      prevGas += (gas[i] - cost[i]);
    }
  }
  if (extraGasRequired > prevGas) {
    return -1;
  } else {
    return result;
  }
}