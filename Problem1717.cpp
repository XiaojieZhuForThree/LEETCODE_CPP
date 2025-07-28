#include <string>
#include <deque>
using std::string;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        std::deque<char> as, bs;
        int ans = 0;
        for (char c : s) {
            if (c == 'a') {
                if (!bs.empty() && y > x) {
                    bs.pop_back();
                    ans += y;
                } else as.push_back(c);
            } else if (c == 'b') {
                if (!as.empty() && x > y) {
                    as.pop_back();
                    ans += x;
                } else bs.push_back(c);
            } else {
                if (x > y) ans += y * std::min(size(as), size(bs));
                else ans += x * std::min(size(as), size(bs));
                as.clear();
                bs.clear();
            }
        }
        if (x > y) ans += y * std::min(size(as), size(bs));
        else ans += x * std::min(size(as), size(bs));
        return ans;
    }
};