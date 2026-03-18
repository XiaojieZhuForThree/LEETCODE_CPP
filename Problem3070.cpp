#include <vector>
using std::vector;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = size(grid), n = size(grid[0]);
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) grid[i][j] += grid[i][j - 1];
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int cur = 0;
            for (int i = 0; i < m; i++) {
                if (cur + grid[i][j] > k) break;
                ans++;
                cur += grid[i][j];
            }
        }
        return ans;
    }
};