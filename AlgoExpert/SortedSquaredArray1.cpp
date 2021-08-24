#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sortedSquaredArray(vector<int> array)
{
    int arraySize = array.size();
    vector<int> sortedSquaredArray(arraySize);
    int startPtr = 0;
    int endPtr = arraySize - 1;
    int index = arraySize - 1;
    while (startPtr <= endPtr)
    {
        if (abs(array[startPtr]) >= abs(array[endPtr]))
        {
            sortedSquaredArray[index--] = array[startPtr] * array[startPtr];
            startPtr++;
        }
        else
        {
            sortedSquaredArray[index--] = array[endPtr] * array[endPtr];
            endPtr--;
        }
    }
    return sortedSquaredArray;
}
