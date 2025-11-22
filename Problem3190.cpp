#include <vector>
using std::vector;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            int mod = i % 3;
            if (mod == 0) continue;
            ans += std::min(mod, 3 - mod);
        }
        return ans;
    }
};