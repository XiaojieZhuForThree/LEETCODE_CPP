#include <vector>
using std::vector;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = size(nums), ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) continue;
            else if (ans == -1) ans = i;
            else ans &= i;
        }
        return ans == -1 ? 0 : ans;
    }
};
