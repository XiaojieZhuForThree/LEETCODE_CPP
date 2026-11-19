#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = size(nums);
        if (n <= 3) return 0;
        sort(begin(nums), end(nums));
        int val1 = nums[n - 3] - nums[0], val2 = nums[n - 2] - nums[1], val3 = nums[n - 1]- nums[2];
        return std::min(val1, std::min(val2, val3));
    }
};
