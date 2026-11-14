#include <vector>
using std::vector;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0; i < size(nums); i++) {
            int cur = 0;
            for (int j = 0; j < r && i + j < size(nums); j++) {
                cur += nums[i + j];
                if (j + 1 < l || cur <= 0) continue;
                ans = std::min(ans, cur);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
