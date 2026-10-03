#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using std::string;
using std::deque;
using std::vector;
using std::max;

class Solution {
public:
    int longestValidParentheses(string s) {
        deque<int> stack;
        vector<int> dp(size(s), 0);
        int ans = 0;
        for (int i = 0; i < size(s); i++) {
            char c = s[i];
            if (c == '(') {
                if (i > 0 && s[i - 1] == ')') {
                    dp[i] = dp[i - 1];
                } else dp[i] = 0;
                stack.push_back(i);
            } else {
                if (stack.empty()) dp[i] = 0;
                else {
                    int j = stack.back();
                    stack.pop_back();
                    dp[i] = i - j + 1 + dp[j];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;        
    }
};
