#include <vector>
using std::vector;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int cur = 0;
        for (int i : nums) {
            cur = (cur * 2 + i) % 5;
            ans.push_back(cur == 0);
        }
        return ans;
    }
};