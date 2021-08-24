#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    int startPtr = 0;
    int endPtr = array.size() - 1;
    while (startPtr < endPtr)
    {
        if (array[startPtr] + array[endPtr] == targetSum)
        {
            return {array[startPtr], array[endPtr]};
        }
        else if (array[startPtr] + array[endPtr] < targetSum)
        {
            startPtr++;
        }
        else
        {
            endPtr--;
        }
    }
    return {};
}
