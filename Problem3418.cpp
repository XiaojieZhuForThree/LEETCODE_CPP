#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector dp(n, vector(m, vector<int>(3, INT_MIN)));
        dp[0][0][1] = dp[0][0][2] = 0, dp[0][0][0] = coins[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 3; k++) {
                    if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                }
        int ans = *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
        return ans;
    }
};