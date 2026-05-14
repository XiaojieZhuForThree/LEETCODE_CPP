#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums) - 1;
        if (nums[n] != n) return false;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return false;
        }
        return true;
    }
};