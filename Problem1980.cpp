#include <string>
#include <vector>
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_set;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = size(nums);
        unordered_set<string> s;
        for (auto& v : nums) s.insert(v);
        for (int i = 0; i < n; i++) ans += '0';
        for (int i = 0; i < n; i++) {
            if (!s.count(ans)) return ans;
            ans[i] = '1';
            if (!s.count(ans)) return ans;
        }
        return ans;
    }
};