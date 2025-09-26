#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int i = size(nums) - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += r - l;
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};