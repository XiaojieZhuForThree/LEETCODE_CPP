#include <vector>
using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = size(bits);
        if (n == 1) return true;
        if (bits[n - 2] == 0) return true;
        vector<int> dp(n + 1, true);
        for (int i = 1; i <= n; i++) {
            if (bits[i - 1] == 0) continue;
            else if (i == 1 || bits[i - 2] == 0) dp[i] = false;
            else dp[i] = dp[i - 2];
        }
        return !dp[n - 2];
    }
};