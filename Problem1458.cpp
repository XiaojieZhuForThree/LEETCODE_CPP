#include <vector>
using std::vector;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1), n = size(nums2);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cur = nums1[i - 1] * nums2[j - 1];
                int val1 = cur + dp[i - 1][j - 1], val2 = dp[i][j - 1], val3 = dp[i - 1][j];
                dp[i][j] = std::max(val1, std::max(val2, val3));
            }
        }
        if (dp[m][n] == 0) {
            int s1 = 1000, b1 = -1000, s2 = 1000, b2 = -1000;
            for (int i : nums1) {
                s1 = std::min(s1, i);
                b1 = std::max(b1, i);
            }
            for (int i : nums2) {
                s2 = std::min(s2, i);
                b2 = std::max(b2, i);
            }
            return std::max(s1 * b2, s2 * b1);
        }
        return dp[m][n];
    }
};