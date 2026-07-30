#include <string>
#include <algorithm>
using std::string;
using std::min;

class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, cur = 1, t = size(word);
        while (t) {
            int r = min(t, 8);
            ans += r * cur;
            t -= r;
            cur++;
        }
        return ans;
    }
};
