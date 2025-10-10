#include <vector>
using std::vector;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> dp;
        long long cur = 0;
        int m = size(mana), n = size(skill);
        for (int i : skill) {
            cur += i * mana[0];
            dp.push_back(cur);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) dp[j] = std::max(dp[j], dp[j - 1] + mana[i] * skill[j - 1]);
            dp[n - 1] += mana[i] * skill[n - 1];
            for (int j = n - 2; j >= 0; j--) dp[j] = dp[j + 1] - mana[i] * skill[j + 1]; 
        }
        return dp[n - 1];
    }
};