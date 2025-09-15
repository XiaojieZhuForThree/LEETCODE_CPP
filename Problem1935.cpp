#include <string>
#include <unordered_set>
using std::string;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        std::unordered_set<char> s;
        for (char c : brokenLetters) s.insert(c);
        int l = 0, ans = 0;
        for (int r = 0; r <= size(text); r++) {
            if (r == size(text) ||  text[r] == ' ') {
                string cur = text.substr(l, r - l);
                bool yes = true;
                for (char c : cur) {
                    if (s.count(c)) {
                        yes = false;
                        break;
                    }
                }
                l = r + 1;
                ans += yes;
            }
        }
        return ans;
    }
};