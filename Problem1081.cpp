#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using std::string;
using std::deque;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    string smallestSubsequence(string s) {
        deque<char> q;
        unordered_map<char, int> m;
        unordered_set<char> seen;
        for (int i = 0; i < size(s); i++) m[s[i]]++;
        for (char c : s) {
            m[c]--;
            if (seen.count(c)) continue;
            while (!q.empty() && q.back() > c && m[q.back()] >= 1) {
                seen.erase(q.back());
                q.pop_back();

            }
            q.push_back(c);
            seen.insert(c);
        }
        string ans = "";
        for (char c : q) ans.push_back(c);
        return ans;
    }
};
