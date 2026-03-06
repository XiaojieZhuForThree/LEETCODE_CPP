#include <string>
using std::string;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        while (i < size(s) && s[i] == '1') i++;
        for(; i < size(s); i++) {
            if (s[i] == '1') return false;
        }
        return true;
    }
};