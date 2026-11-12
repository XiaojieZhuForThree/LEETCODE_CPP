#include <vector>
using std::vector;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int pa = 1, pd = 1, ans = 1;
        for (int i = 1; i < size(nums); i++) {
            if (nums[i] > nums[i - 1]) {
                pa++;
                pd = 1;
            } else if (nums[i] < nums[i - 1]) {
                pa = 1;
                pd++;
            } else {
                pa = 1;
                pd = 1;
            }
            ans = std::max(ans, std::max(pa, pd));
        }
        return ans;
    }
};
