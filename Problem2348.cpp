#include <vector>
using std::vector;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, cur = 0;
        for (int i : nums) {
            if (i) cur = 0;
            else ans += ++cur;
        }
        return ans;
    }
};