#include <vector>
#include <bitset>
using std::vector;
using std::bitset;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2) return false;
        vector<bitset<100>> dp(n + 1);
        for (int i = 0; i < m; i++) {
            dp[0][0] = !i;
            for (int j = 0; j < n; j++) dp[j + 1] = grid[i][j] == '(' ? (dp[j] | dp[j + 1]) << 1: (dp[j] | dp[j + 1]) >> 1;
        }
        return dp[n][0];
    }
};
