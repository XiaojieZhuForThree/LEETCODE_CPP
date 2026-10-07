#include <unordered_set>
#include <string>
#include <vector>
using std::unordered_set;
using std::string;
using std::vector;

class Solution {
unordered_set<string> seen;
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        string b = "";
        dfs(s, b, 0, l, r);
        vector<string> v;
        for (auto& cand : seen) v.push_back(cand);
        return v;
    }

private:
    void dfs(string& s, string& cur, int i, int l, int r) {
        if (i == size(s)) {
            if (l == 0 && r == 0 && yes(cur)) seen.insert(cur);
            return;
        }
        char c = s[i];
        cur += c;
        dfs(s, cur, i + 1, l, r);
        cur.pop_back();
        if (c == '(' && l > 0) dfs(s, cur, i + 1, l - 1, r);
        else if (c == ')' && r > 0) dfs(s, cur, i + 1, l, r - 1);
    }
    bool yes(string& s) {
        int l = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l == 0) return false;
                else l--;
            } 
        }
        return l == 0;
    }
};
