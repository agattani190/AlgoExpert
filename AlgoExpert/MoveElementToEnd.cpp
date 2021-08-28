#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int arraySize = array.size();
  int leftPtr = 0;
  int rightPtr = arraySize - 1;
  while (leftPtr < rightPtr) {
    if (array[rightPtr] != toMove) {
      if (array[leftPtr] == toMove) {
        swap(array[leftPtr], array[rightPtr]);
        rightPtr--;
      }
      leftPtr++;
    } else {
      rightPtr--;
    }
  }
  return array;
}