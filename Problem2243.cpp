#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string digitSum(string s, int k) {
        if (size(s) <= k) return s;
        string nxt = "";
        for (int i = 0; i < size(s); i += min(k, (int)(size(s)) - i)) {
            if (i + k <= size(s)) nxt += helper(s.substr(i, k));
            else nxt += helper(s.substr(i, size(s) - i));
        }
        return digitSum(nxt, k);
    }
private:
    string helper(string s) {
        int ans = 0;
        for (char c : s) ans += c - '0';
        return to_string(ans);
    }
};
