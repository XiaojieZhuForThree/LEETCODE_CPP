#include <vector>
using std::vector;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mi = nums[0], ma = nums[0];
        for (long long i : nums) {
            mi = std::min(mi, i);
            ma = std::max(ma, i);
        }
        return (ma - mi) * k;
    }
};
