#include <vector>
using std::vector;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = size(grid), n = size(grid[0]);
        const int MOD = 1000000007;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k, 0)));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cur = grid[i - 1][j - 1];
                if (i == 1 && j == 1) {
                    dp[i][j][cur % k] = 1;
                    continue;
                }
                vector<int> nxt(k, 0);
                for (int p = 0; p < k; p++) {
                    int t = (p + cur) % k;
                    dp[i][j][t] = (dp[i - 1][j][p] + dp[i][j - 1][p]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};