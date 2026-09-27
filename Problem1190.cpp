#include <string>
#include <algorithm>
using std::string;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        for (int i = 0; i < size(s);) {
            if (s[i] == '(') {
                int cnt = 1, j = i + 1;
                while (cnt > 0) {
                    if (s[j] == '(') cnt++;
                    else if (s[j] == ')') cnt--;
                    j++;
                }
                j--;
                string nxt = reverseParentheses(s.substr(i + 1, j - i - 1));
                reverse(begin(nxt), end(nxt));
                for (char c : nxt) ans += c;
                i = j + 1;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
