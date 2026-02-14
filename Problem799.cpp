#include <vector>
using std::vector;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, 0));
        dp[0][0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (j <= i - 1 && dp[i - 1][j] > 1) dp[i][j] += (dp[i - 1][j] - 1) / 2;
                if (j - 1 >= 0 && dp[i - 1][j - 1] > 1) dp[i][j] += (dp[i - 1][j - 1] - 1) / 2;
            }
        }
        if (dp[query_row][query_glass] > 1) return 1.0;
        return dp[query_row][query_glass];
    }
};