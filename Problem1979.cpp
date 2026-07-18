#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;
using std::gcd;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int l = nums[0], r = nums[size(nums) - 1];
        return gcd(l, r);
    }
};
