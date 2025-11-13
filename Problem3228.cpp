#include <string>
using std::string;

class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cur = 0;
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '1') {
                if (i > 0 && s[i - 1] == '0') ans += cur;
                cur++;
            }
        }
        if (s[size(s) - 1] == '0') ans += cur;
        return ans;
    }
};