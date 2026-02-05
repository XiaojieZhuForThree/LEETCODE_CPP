#include <vector>
using std::vector;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(size(nums), 0);
        int n = size(nums);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            else if (nums[i] > 0) ans[i] = nums[(i + nums[i] + n) % n];
            else ans[i] = nums[(n + (i + nums[i]) % n) % n];
        }
        return ans;
    }
};