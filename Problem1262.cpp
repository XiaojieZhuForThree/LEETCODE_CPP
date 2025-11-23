#include <vector>
using std::vector;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int i : nums) {
            vector<int> nxt(dp);
            for (int j = 0; j < 3; j++) {
                int k = i + dp[j], t = k % 3;
                nxt[t] = std::max(k, nxt[t]);
            }
            dp = nxt;
        }
        return dp[0];
    }
};