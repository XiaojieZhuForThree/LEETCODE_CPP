#include <string>
using std::string;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool s[26], b[26], n[26];
        for (char c : word) {
            if (islower(c)) {
                if (b[toupper(c) - 'A']) n[c - 'a'] = true;
                else s[c - 'a'] = true;
            } else b[c - 'A'] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (s[i] && b[i] && !n[i]) ans++;
        }
        return ans;
    }
};
