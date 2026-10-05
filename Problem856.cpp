#include <string>
using std::string;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, l = 0, i = 0;
        for (int j = 0; j < size(s); j++) {
            if (s[j] == '(') l++;
            else l--;
            if (l == 0) {
                if (j - i == 1) ans += 1;
                else ans += 2 * scoreOfParentheses(s.substr(i + 1, j - i - 1));
                i = j + 1;
            }
        }
        return ans;
    }
};
