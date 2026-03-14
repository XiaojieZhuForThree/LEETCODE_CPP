#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string getHappyString(int n, int k) {
        auto lst = helper(n);
        if (k > size(lst)) return "";
        return lst[k - 1];
    }
private:
    vector<string> helper(int n) {
        if (n == 1) return {"a", "b", "c"};
        auto prev = helper(n - 1);
        vector<string> ans;
        for (auto& s : prev) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[size(s) - 1]) continue;
                ans.push_back(s + c);   
            }
        }
        return ans;
    }
};