#include <vector>
using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < size(triangle); i++) {
            for (int j = 0; j < size(triangle[i]); j++) {
                int cand1 = INT_MAX, cand2 = INT_MAX;
                if (j > 0) cand1 = triangle[i - 1][j - 1];
                if (j < size(triangle[i - 1])) cand2 = triangle[i - 1][j];
                triangle[i][j] += std::min(cand1, cand2);
            }
        }
        int ans = INT_MAX;
        for (int i : triangle[size(triangle) - 1]) ans = std::min(ans, i);
        return ans;
    }
};