#include <vector>
using std::vector;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int v = *std::max_element(begin(nums), end(nums)), ans = 0;
        for (int i = 0; i < size(nums);) {
            if (nums[i] != v) i++;
            else {
                int j = i;
                while (j < size(nums) && nums[j] == v) j++;
                ans = std::max(ans, j - i);
                i = j;
            }
        }
        return ans;
    }
};