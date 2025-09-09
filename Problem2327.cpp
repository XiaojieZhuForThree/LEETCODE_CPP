#include <vector>
#include <algorithm>
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        std::vector<long long> dp(n + 1);
        dp[1] = 1;
        int share = 0, mod = 1e9 + 7, res = 0;
        for (int i = 2; i <= n; i++) {
            share = (share + dp[std::max(i - delay, 0)] - dp[std::max(i - forget, 0)] + mod) % mod;
            dp[i] = share;
        }
        for (int i = n - forget + 1; i <= n; i++) res = (res + dp[i]) % mod;
        return res;
    }
};