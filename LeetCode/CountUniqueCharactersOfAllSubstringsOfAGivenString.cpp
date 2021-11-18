#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> indices(26, vector<int>());
        for(int i=0; i<n; i++) {
            indices[s[i] - 'A'].push_back(i);
        }
        int result = 0;
        int numOfStartPositions, numOfEndPositions;
        for(int i=0;i<26;i++) {
            for(int j=0;j<indices[i].size();j++) {
                if(j>0) {
                    numOfStartPositions = indices[i][j] - indices[i][j-1];
                } else {
                    numOfStartPositions = indices[i][j] + 1;
                }
                
                if(j<indices[i].size()-1) {
                    numOfEndPositions = indices[i][j+1] - indices[i][j];
                } else {
                    numOfEndPositions = n - indices[i][j];
                }
                
                result += (numOfStartPositions * numOfEndPositions);
            }
        }
        return result;
    }