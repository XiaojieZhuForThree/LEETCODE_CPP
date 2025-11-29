#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int i : nums) ans += i;
        return ans % k;
    }
};