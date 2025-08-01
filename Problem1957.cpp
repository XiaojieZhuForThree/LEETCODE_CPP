#include <string>
using std::string;

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int i = 0, j = 0;
        while (i < size(s)) {
            j = i;
            while (j < size(s) && s[j] == s[i]) j++;
            for (int k = 0; k < std::min(2, j - i); k++) ans.push_back(s[i]);
            i = j;
        }
        return ans;
    }
};