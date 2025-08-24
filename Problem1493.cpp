#include <vector>
using std::vector;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cur = 0, ans = 0, n = size(nums);
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = cur;
            if (nums[i] == 0) cur = 0;
            else cur++;
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] += cur;
            ans = std::max(ans, dp[i]);
            if (nums[i] == 0) cur = 0;
            else cur++;
        }
        return ans;
    }
};