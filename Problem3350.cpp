#include <vector>
using std::vector;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = size(nums);
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) continue;
            dp[i] = 1 + dp[i - 1];
        }
        int l = 1, r = size(nums);
        while (l < r) {
            int m = l + (r - l) / 2;
            if (yes(dp, m)) l = m + 1;
            else r = m;
        }
        return yes(dp, l) ? l : l - 1;
    }
private:
    bool yes(vector<int>& dp, int k) {
        for (int i = 0; i < size(dp); i++) {
            if (dp[i] >= k && i - k >= 0 && dp[i - k] >= k) return true;
        }
        return false;
    }
};