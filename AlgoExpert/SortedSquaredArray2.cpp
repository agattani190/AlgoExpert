#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sortedSquaredArray(vector<int> array)
{
    int arraySize = array.size();
    vector<int> sortedSquaredArray(arraySize);
    int indexOfFirstNonNegativeNumber = lower_bound(array.begin(), array.end(), 0) - array.begin();
    int rightPtr = indexOfFirstNonNegativeNumber;
    int leftPtr = rightPtr - 1;
    int index = 0;
    while (leftPtr >= 0 && rightPtr < arraySize)
    {
        if (abs(array[leftPtr]) <= abs(array[rightPtr]))
        {
            sortedSquaredArray[index++] = array[leftPtr] * array[leftPtr];
            leftPtr--;
        }
        else
        {
            sortedSquaredArray[index++] = array[rightPtr] * array[rightPtr];
            rightPtr++;
        }
    }
    while (leftPtr >= 0)
    {
        sortedSquaredArray[index++] = array[leftPtr] * array[leftPtr];
        leftPtr--;
    }
    while (rightPtr < arraySize)
    {
        sortedSquaredArray[index++] = array[rightPtr] * array[rightPtr];
        rightPtr++;
    }
    return sortedSquaredArray;
}
