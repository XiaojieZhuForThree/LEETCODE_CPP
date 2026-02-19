#include <string>
using std::string;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int p0 = 0, p1 = 0, ans = 0;
        if (s[0] == '0') p0 = 1;
        else p1 = 1;
        for (int i = 1; i < size(s); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1')  p0 = 1;
                else p0++;
                if (p0 > 0 && p1 > 0 && p0 <= p1) ans++;
            } else {
                if (s[i - 1] == '0') p1 = 1;
                else p1++;
                if (p0 > 0 && p1 > 0 && p1 <= p0) ans++;
            }
        }
        return ans;
    }
};