#include <vector>
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = size(nums), ans = 1;
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));
        dp[0][nums[0] % k] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][nums[i] % k] = 1;
            for (int j = 0; j < i; j++) {
                int t = (nums[i] + nums[j]) % k;
                int cand = 2;
                if (dp[j][t] > 0) cand = dp[j][t] + 1;
                dp[i][t] = std::max(dp[i][t], cand);
                ans = std::max(ans, dp[i][t]);
            }
        }
        return ans;
    }
};