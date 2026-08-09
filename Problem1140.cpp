#include <vector>
using std::vector;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int s = 0;
        for (int i : piles) s += i;
        vector<vector<int>> dp(size(piles) + 1, vector<int>(2 * size(piles) + 1, -1));
        return dfs(piles, 0, 1, s, dp);
    }
private:
    int dfs(vector<int>& p, int i, int m, int s, vector<vector<int>>& dp) {
        if (i >= size(p)) return 0;
        if (dp[i][m] != -1) return dp[i][m];
        int cur = 0, ans = 0;
        for (int j = 0; j < 2 * m && i + j < size(p); j++) {
            cur += p[i + j];
            ans = std::max(ans, s - dfs(p, i + j + 1, std::max(m, j + 1), s - cur, dp));
        }
        dp[i][m] = ans;
        return ans;
    }
};
