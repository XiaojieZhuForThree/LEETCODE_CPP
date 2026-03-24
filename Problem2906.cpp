#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), mod = 12345, cur = 1;
        vector<vector<int>> pre(m, vector<int>(n, 1)), suf(m, vector<int>(n, 1)), ans(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i][j] = cur;
                cur *= (grid[i][j] % mod);
                cur %= mod;
            }
        }
        cur = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                suf[i][j] = cur;
                cur *= (grid[i][j] % mod);
                cur %= mod;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = (pre[i][j] * suf[i][j]) % mod;
            }
        }
        return ans;
    }
};
