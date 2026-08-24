#include <vector>
using std::vector;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = size(stones);
        for (int i = 1; i < n; i++) stones[i] += stones[i - 1];
        vector<int> dp(n + 1, 0);
        dp[2] = stones[n - 1];
        for (int i = 3; i <= n; i++) dp[i] = std::max(dp[i - 1], stones[n - 1 - (i - 2)] - dp[i - 1]);
        return dp[n];
    }
};
