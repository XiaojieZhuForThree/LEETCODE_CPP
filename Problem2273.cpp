#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string cur = "";
        for (auto& w : words) {
            if (helper(w) == cur) continue;
            ans.push_back(w);
            cur = helper(w);
        }
        return ans;
    }
private:
    string helper(string& s) {
        string b = s;
        sort(begin(b), end(b));
        return b;
    }
};