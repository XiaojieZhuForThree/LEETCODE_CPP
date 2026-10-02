#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) return {"()"};
        auto prev = generateParenthesis(n - 1);
        unordered_set<string> s;
        for (string& p : prev) {
            for (int i = 0; i < size(p); i++) {
                s.insert(p.substr(0, i) + "()" + p.substr(i, size(p) - i));
            }
        }
        vector<string> ans;
        for (auto& t : s) ans.push_back(t);
        return ans;      
    }
};
