#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::min;

class Solution {
public:
    int dp[210][110];
    vector<int> fac[210];
    int num(string st) {
        int n = st.length();
        int ans = 1e9;
        for (auto it : fac[st.length()]) {
            int nu = n / it;
            int cur = 0;
            for (int i = 0; i < nu / 2; i++) {
                int i2 = nu - i - 1;
                for (int j = 0; j < it; j++) {
                    if (st[i * it + j] != st[i2 * it + j]) cur++;
                }
            }

            ans = min(ans, cur);
        }
        return ans;
    }

    int minimumChanges(string st, int k) {
        int n = st.length();
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0) fac[i].push_back(j);
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) dp[i][j] = 1e9;
        }

        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                string cur = st.substr(j, i - j + 1);
                int add = num(cur);
                for (int l = 0; l < k; l++) dp[i + 1][l + 1] = min(dp[i + 1][l + 1], dp[j][l] + add);
            }
        }
        return dp[n][k];
    }
};
