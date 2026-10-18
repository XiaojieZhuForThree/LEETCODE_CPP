#include <vector>
using std::vector;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp;
    int numOfWays(vector<int>& nums) {
        int n = size(nums);
        dp.resize(n + 1, vector<long long>(n + 1, 0));
        return total(nums) - 1;
    }
private:
    long long total(vector<int>& nums) {
        if (size(nums) <= 2) return 1;
        vector<int> l, r;
        int h = nums[0];
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] > h) r.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        long long lc = total(l), rc = total(r);
        return ((lc * rc) % MOD * helper(size(l) + size(r), size(l))) % MOD;
    }
    long long helper(int t, int c) {
        if (t < c) return 0;
        if (c == 0) return 1;
        if (dp[t][c] != 0) return dp[t][c];
        long long ans = (helper(t - 1, c) + helper(t - 1, c - 1)) % MOD;
        dp[t][c] = ans;
        return ans;
    }
};
