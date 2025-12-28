#include <vector>
using std::vector;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < 0) ans++;
            }
        }
        return ans;
    }
};