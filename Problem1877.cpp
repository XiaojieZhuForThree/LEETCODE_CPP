#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int l = 0, r = size(nums) - 1, ans = 0;
        while (l < r) ans = std::max(ans, nums[l++] + nums[r--]);
        return ans;
    }
};