#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        string ans = "";
        for (auto& p : m) {
            if (p.second % 2 == 1) {
                ans += p.first;
                m[p.first]--;
            }
        }
        for (char c = 'z'; c >= 'a'; c--) {
            if (!m.count(c)) continue;
            string nxt = "";
            for (int i = 0; i * 2 < m[c]; i++) nxt += c;
            ans = nxt + ans + nxt;
        }
        return ans;
    }
};
