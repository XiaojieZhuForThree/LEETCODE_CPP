#include <string>
#include <algorithm>
using std::string;

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        return helper(ans, s, 0);
    }
private:
    string helper(string& cur, string& s, int i) {
        if (i == size(s)) return cur;
        char c = s[i];
        if (c == '*') {
            if (size(cur) > 0) cur.pop_back();
        } else if (c == '#') cur = cur + cur;
        else if (c == '%') reverse(begin(cur), end(cur));
        else cur += s[i];
        return helper(cur, s, i + 1);
    }
};
