#include <math.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)
int twoEggDrop(int n) { return ceil(sqrt(1 + (8 * n)) / 2 - 0.5); }