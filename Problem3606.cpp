#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = size(code);
        vector<int> ans;
        std::unordered_map<string, int> v = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
        for (int i = 0; i < n; i++) {
            if (!valid(code[i])) continue;
            if (!v.count(businessLine[i])) continue;
            if (!isActive[i]) continue;
            ans.push_back(i);
        }
        std::sort(begin(ans), end(ans), [&v, &businessLine, &code](int i, int j) {
            if (v[businessLine[i]] == v[businessLine[j]]) {
                return code[i] < code[j];
            }
            return v[businessLine[i]] < v[businessLine[j]];
        });
        vector<string> res;
        for (int i : ans) res.push_back(code[i]);
        return res;
    }
private:
    bool valid(string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
};