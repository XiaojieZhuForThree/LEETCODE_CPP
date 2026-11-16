#include <string>
#include <algorithm>
using std::string;
using std::min;
using std::to_string;

class Solution {
public:
    string digitSum(string s, int k) {
        int n = size(s);
        if (n <= k) return s;
        string nxt = "";
        for (int i = 0; i < n; i += min(k, n - i)) {
            if (i + k <= n) nxt += helper(s.substr(i, k));
            else nxt += helper(s.substr(i, n - i));
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
