#include <string>
using std::string;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, d = 0;
        for (char c : s) {
            if (c == '(') d++;
            else if (c == ')') d--;
            ans = std::max(ans, d);
        }
        return ans;
    }
};
