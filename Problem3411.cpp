#include <vector>
#include <numeric>
#include <algorithm>
using std::vector;
using std::lcm;
using std::gcd;
using std::max;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < size(nums); i++) {
            long long prod = nums[i], l = nums[i], g = nums[i];
            for(int j = i + 1; j < size(nums); j++){
                prod = prod * nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);
                if(prod > l * g) break;
                if(prod == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
