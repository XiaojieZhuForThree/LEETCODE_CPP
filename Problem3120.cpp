#include <string>
using std::string;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool s[26], b[26];
        int ans = 0;
        for (char c : word) {
            if (islower(c)) s[c - 'a'] = true;
            else b[c - 'A'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (s[i] && b[i]) ans++;
        }
        return ans;
    }
};
