#include <vector>
#include <math.h>
using namespace std;

// Time Complexity: O(sqrt(c))
// Space Complexity: O(n)
bool judgeSquareSum(int c) {
    int num1 = 0;
    int num2 = sqrt(c);
    while(num1 <= num2) {
        if (c - num1*num1 == num2*num2) {
            return true;
        } else if(c - num1*num1 > num2*num2) {
            num1++;
        } else {
            num2--;
        }
    }
    return false;
}