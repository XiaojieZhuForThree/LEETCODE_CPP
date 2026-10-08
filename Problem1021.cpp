#include <string>
#include <deque>
using std::string;
using std::deque;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        deque<char> q;
        int l = 0;
        for (char c : s) {
            q.push_back(c);
            if (c == '(') l++;
            else l--;
            if (l == 0) {
                q.pop_front();
                q.pop_back();
                while (!q.empty()) {
                    ans += q.front();
                    q.pop_front();
                }
            }
        }
        return ans;
    }
};
