#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;
using std::max;
using std::gcd;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int cur = nums[0];
        vector<int> v;
        for (int i : nums) {
            cur = max(cur, i);
            v.push_back(gcd(cur, i));
        }
        sort(begin(v), end(v));
        int l = 0, r = size(v) - 1;
        while (l < r) ans += gcd(v[l++], v[r--]);
        return ans;
    }
};
