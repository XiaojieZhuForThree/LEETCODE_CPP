#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        std::sort(begin(nums), end(nums));
        for (int i : nums) {
            if (i == ans) ans *= 2;
        }
        return ans;
    }
};