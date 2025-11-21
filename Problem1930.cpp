#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::vector<int> l(26, -1), r(26, -1);
        std::vector<std::vector<int>> seen(26, std::vector<int>(26, 0));
        int ans = 0;
        for (int i = 0; i < size(s); i++) {
            char c = s[i];
            if (l[c - 'a'] == -1) l[c - 'a'] = i;
            r[c - 'a'] = i;
        }
        for (int i = 1; i + 1 < size(s); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (l[c - 'a'] != -1 && l[c - 'a'] < i && r[c - 'a'] != -1 && r[c - 'a'] > i && seen[c - 'a'][s[i] - 'a'] == 0) {
                    seen[c - 'a'][s[i] - 'a'] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};