#include <string>
using std::string;

class Solution {
public:
    bool hasSameDigits(string s) {
        if (size(s) == 2) return s[0] == s[1];
        string nxt = "";
        for (int i = 0; i < size(s) - 1; i++) nxt += std::to_string((s[i] - '0' + s[i + 1] - '0') % 10);
        return hasSameDigits(nxt);
    }
};