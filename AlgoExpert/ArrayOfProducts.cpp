#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> arrayOfProducts(vector<int> array) {
  int arraySize = array.size();
  vector<int> leftProduct(arraySize);
  vector<int> rightProduct(arraySize);
  leftProduct[0] = 1;
  rightProduct[arraySize - 1] = 1;
  for (int i = 1; i < arraySize; i++) {
    leftProduct[i] = leftProduct[i - 1] * array[i - 1];
    rightProduct[arraySize - i - 1] =
        rightProduct[arraySize - i] * array[arraySize - i];
  }
  vector<int> result(arraySize);
  for (int i = 0; i < arraySize; i++) {
    result[i] = leftProduct[i] * rightProduct[i];
  }
  return result;
}
