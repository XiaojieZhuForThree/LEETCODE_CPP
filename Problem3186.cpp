#include <unordered_map>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::unordered_map<int, int> m;
        for (int i : power) m[i]++;
        vector<long long> v, dp;
        for (auto& p : m) v.push_back(p.first);
        sort(begin(v), end(v));
        dp.resize(size(v), 0);
        for (int i = 0; i < size(v); i++) {
            long long v1 = i - 1 >= 0 ? dp[i - 1] : 0, v2 = v[i] * m[v[i]];
            int j = i - 1;
            while (j >= 0 && v[j] >= v[i] - 2) j--;
            if (j >= 0) v2 += dp[j];
            dp[i] = std::max(v1, v2);
        }
        return dp[size(v) - 1];
    }
};