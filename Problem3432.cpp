#include <vector>
using std::vector;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        for (int i = 1; i < size(nums); i++) nums[i] += nums[i - 1];
        int ans = 0;
        for (int i = 0; i < size(nums) - 1; i++) {
            if ((nums[size(nums) - 1] - 2 * nums[i]) % 2 == 0) ans++;
        }
        return ans;
    }
};