#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;
        int L = limit + 1;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));

        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                dp0[i][j] = (1LL * dp0[i-1][j] + dp1[i-1][j] - (i >= L ? dp1[i-L][j] : 0)) % mod;
                dp1[i][j] = (1LL * dp1[i][j-1] + dp0[i][j-1] - (j >= L ? dp0[i][j-L] : 0)) % mod;
                dp0[i][j] = (dp0[i][j] + mod) % mod;
                dp1[i][j] = (dp1[i][j] + mod) % mod;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};