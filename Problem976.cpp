#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = size(nums) - 1; i - 2 >= 0; i--) {
            if (nums[i] < nums[i - 1] + nums[i - 2]) return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;
    }
};