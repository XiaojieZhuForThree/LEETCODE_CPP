#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = size(stoneValue);
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int k = 0, take = 0; k < 3 & i + k < n; k++) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";        
    }
};
