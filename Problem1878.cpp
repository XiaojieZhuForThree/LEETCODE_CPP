#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector;
using std::unordered_set;
using std::greater;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        unordered_set<int> s;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(grid[i][j]);
                for (int k = 1; i - 2 * k >= 0 && j - k >= 0 && j + k < n; k++) {
                    s.insert(helper(grid, i, j, k));
                }
            }
        }
        vector<int> ans;
        for (int i : s) ans.push_back(i);
        sort(begin(ans), end(ans), greater<int>());
        if (size(ans) <= 3) return ans;
        return {ans[0], ans[1], ans[2]};
    }
private:
    int helper(vector<vector<int>>& grid, int i, int j, int k) {
        int ans = grid[i][j] + grid[i - 2 * k][j];
        for (int t = 1; t <= k; t++) {
            ans += grid[i - t][j - t] + grid[i - t][j + t];
        }
        for (int t = 1; t < k; t++) {
            ans += grid[i - 2 * k + t][j - t] + grid[i - 2 * k + t][j + t];
        }
        return ans;
    }
};