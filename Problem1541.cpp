#include <string>
using std::string;

class Solution {
public:
    int minInsertions(string s) {
        int l = 0, ans = 0;
        for (int i = 0; i < size(s);) {
            char c = s[i];
            if (c == '(') {
                l++;
                i++;
            }
            else {
                if (i + 1 == size(s) || s[i + 1] != ')') {
                    ans++;
                    i++;
                }
                else i += 2;
                if (l == 0) ans++;
                else l--;
            }
        }
        
        return ans + l * 2;
    }
};
