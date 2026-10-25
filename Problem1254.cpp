#include <vector>
using std::vector;

class Solution {
public:
    bool yes;
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0, m = size(grid), n = size(grid[0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    yes = true;
                    dfs(grid, i, j);
                    ans += yes;
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = size(grid), n = size(grid[0]);
        if (i < 0 || 0 || i >= m || j < 0 || j >= n) {
            yes = false;
            return;
        }
        if (grid[i][j] == 1) return;
        grid[i][j] = 1;
        for (auto& d : dirs) dfs(grid, i + d[0], j + d[1]);
    }
};
