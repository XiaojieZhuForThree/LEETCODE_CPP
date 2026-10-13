#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < size(nums); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(begin(nums), end(nums));
        long long ans = 0;
        int l = 0, r = size(nums) - 1;
        while (l < r) ans += nums[r--] - nums[l++];
        if (l == r) ans += nums[l];
        return ans;
    }
};
