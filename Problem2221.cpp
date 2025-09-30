#include <vector>
using std::vector;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (size(nums) > 1) {
            vector<int> nxt;
            for (int i = 0; i < size(nums) - 1; i++) nxt.push_back((nums[i] + nums[i + 1]) % 10);
            nums = nxt;
        }
        return nums[0];
    }
};