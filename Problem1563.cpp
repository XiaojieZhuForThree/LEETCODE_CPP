#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    vector<vector<int>> dp;
    int stoneGameV(vector<int>& A) {
        int n = size(A);
        dp.resize(n, vector<int>(n, -1));
        for (int i = 1; i < n; i++) A[i] += A[i - 1];
        int t = A[n - 1];
        return helper(A, 0, n - 1);
    }
private:
    int helper(vector<int>& A, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int val1 = A[i] - (l > 0 ? A[l - 1] : 0), val2 = A[r] - A[i];
            if (val1 < val2) ans = max(ans, val1 + helper(A, l, i));
            else if (val1 > val2) ans = max(ans, val2 + helper(A, i + 1, r));
            else ans = max(ans, max(val1 + helper(A, l, i), val2 + helper(A, i + 1, r)));
        }
        dp[l][r] = ans;
        return ans;
    }
};
