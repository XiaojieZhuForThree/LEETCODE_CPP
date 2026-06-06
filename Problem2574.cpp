#include <vector>
using std::vector;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = size(nums);
        vector<int> l(n, 0), r(n, 0), ans(n, 0);
        int cur = 0;
        for (int i = 1; i < n; i++) {
            cur += nums[i - 1];
            l[i] = cur;
        }
        cur = 0;
        for (int i = n - 2; i >= 0; i--) {
            cur += nums[i + 1];
            r[i] = cur;
        }
        for (int i = 0; i < n; i++) ans[i] = abs(l[i] - r[i]);
        return ans;
    }
};