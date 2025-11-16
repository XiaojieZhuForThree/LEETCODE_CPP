#include <string>
using std::string;
class Solution {
public:
    int numSub(string s) {
        int n = size(s);
        int ans = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') dp[i] = 0;
            else {
                dp[i] = 1 + dp[i - 1];
                ans += dp[i];
                ans %= 1000000007;
            }
        }
        return ans;
    }
};