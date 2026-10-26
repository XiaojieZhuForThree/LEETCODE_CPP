#include <vector>
using std::vector;

class Solution {
public:
    int s, m, n, o;
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        m = size(grid);
        n = size(grid[0]);
        o = k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    s = 0;
                    dfs(grid, i, j);
                    ans += (s % k == 0);
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        s += (grid[i][j]) % o;
        s %= o;
        grid[i][j] = 0;
        for (auto& d : dirs) dfs(grid, i + d[0], j + d[1]);
    }
};
