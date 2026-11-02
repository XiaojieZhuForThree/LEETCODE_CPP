#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int l = 0, r = size(nums) - 1, ans = 0;
        while (l < r) ans += nums[r--] - nums[l++];
        return ans;
    }
};
