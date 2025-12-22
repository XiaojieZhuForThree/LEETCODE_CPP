#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = size(strs), n = size(strs[0]);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < m; k++) {
                    if (strs[k][j] > strs[k][i]) break;
                    if (k == m - 1) dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        int max = 0;
        for (int i : dp) max = std::max(i, max);
        return n - max;        
    }
};