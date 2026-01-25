#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = INT_MAX;
        for (int i = k - 1; i < size(nums); i++) ans = std::min(ans, nums[i] - nums[i - k + 1]);
        return ans;
    }
};