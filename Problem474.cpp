#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<std::pair<int, int>> v;
        for (auto& s : strs) v.push_back(helper(s));
        vector<vector<vector<int>>> dp(size(v) + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        dp[0][0][0] = 0;
        for (int i = 1; i <= size(v); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (dp[i - 1][j][k] != -1) dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i][j][k]);
                    int pj = j - v[i - 1].first, pk = k - v[i - 1].second;
                    if (pj <  0 || pk < 0) continue;
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][pj][pk] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= size(v); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) ans = std::max(ans, dp[i][j][k]);
            }
        }
        return ans;
    }
private:
    std::pair<int, int> helper(string& s) {
        int z = 0, o = 0;
        for (char c : s) {
            if (c == '0') z++;
            else o++;
        }
        return {z, o};
    }
};