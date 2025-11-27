#include <vector>
using std::vector;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0, n = size(nums);
        vector<long long> dp(n, -1);
        long long cur = 0;
        for (; r < n; r++) {
            cur += nums[r];
            if (r >= k) cur -= nums[l++];
            if (r >= k - 1) dp[r] = cur;
        }
        for (int i = k - 1; i < n; i++) {
            if (i - k < 0) continue;
            if (dp[i - k] < 0) continue;
            dp[i] += dp[i - k];
        }
        long long ans = LLONG_MIN;
        for (int i = k - 1; i < n; i++) ans = std::max(ans, dp[i]);
        return ans;
    }
};