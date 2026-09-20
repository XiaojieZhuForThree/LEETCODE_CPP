#include <string>
using std::string;

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < size(s); i++) ans += ('z' - s[i] + 1) * (i + 1);
        return ans;
    }
};
