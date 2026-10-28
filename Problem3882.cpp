#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;
    int minCost(vector<vector<int>>& grid) {
        m = size(grid);
        n = size(grid[0]);
        dp.resize(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(grid, 0, 0, grid[0][0]);
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int cur) {
        int m = size(grid), n = size(grid[0]);
        if (i < 0 || i >= m || j < 0 || j >= n) return 1024;
        if (i == m - 1 && j == n - 1) return cur;
        if (dp[i][j][cur] != -1) return dp[i][j][cur];
        int ans = 1024;
        if (i + 1 < m) ans = min(ans, dfs(grid, i + 1, j, cur ^ grid[i + 1][j]));
        if (j + 1 < n) ans = min(ans, dfs(grid, i, j + 1, cur ^ grid[i][j + 1]));
        dp[i][j][cur] = ans;
        return ans;
    }
};