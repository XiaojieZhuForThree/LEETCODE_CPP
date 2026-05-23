#include <vector>
using std::vector;

class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0, n = size(nums);
        while (i + 1 < n && nums[i] <= nums[i + 1]) i++;
        i++;
        if (i == n) return true;
        for (; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return nums[n - 1] <= nums[0];
    }
};