#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> pwrs;
        int MOD = (int)(1e9 + 7);
        for (int i = 0; i <= 31; i++) {
            if ((1 << i) & n) pwrs.push_back((1 << i));
        }
        vector<int> ans;
        for (auto& q : queries) {
            long long cur = 1;
            for (int i = q[0]; i <= q[1]; i++) {
                cur *= pwrs[i];
                cur %= MOD;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};