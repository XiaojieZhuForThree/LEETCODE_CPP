#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int v1 = 0, v2 = 0, m = size(s1), n = size(s2);
        for (char c : s1) v1 += c;
        for (char c : s2) v2 += c;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                else dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return v1 + v2 - 2 * dp[m][n];
    }
};