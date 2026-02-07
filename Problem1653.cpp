#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> dp;
        vector<int> ans(size(s) + 1, 0);
        int cur = 0;
        for (char c : s) {
            if (c == 'b') cur++;
            dp.push_back(cur);
        }
        for (int i = 0; i < size(s); i++) {
            if (s[i] == 'b') ans[i + 1] = ans[i];
            else ans[i + 1] = std::min(dp[i], 1 + ans[i]);
        }
        return ans[size(s)];
    }
};