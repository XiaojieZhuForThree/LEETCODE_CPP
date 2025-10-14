#include <vector>
using std::vector;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) continue;
            dp[i] = 1 + dp[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] >= k && i - k >= 0 && dp[i - k] >= k) return true;
        }
        return false;
    }
};