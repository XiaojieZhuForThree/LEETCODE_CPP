#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    vector<vector<int>> dp;
    bool stoneGame(vector<int>& piles) {
        dp.resize(size(piles), vector<int>(size(piles), -1));
        int s = sum(piles), b = helper(piles, 0, size(piles) - 1, s);
        return b >= s - b;
    }
private:
    int sum(vector<int>& n) {
        int ans = 0;
        for (int i : n) ans += i;
        return ans;
    }
    int helper(vector<int>& n, int l, int r, int s) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int val1 = n[l] + s - helper(n, l + 1, r, s - n[l]), val2 = n[r] + s - helper(n, l, r - 1, s - n[r]);
        dp[l][r] = max(val1, val2);
        return dp[l][r];
    }
};
