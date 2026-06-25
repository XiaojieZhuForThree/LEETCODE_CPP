#include <vector>
using std::vector;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = size(nums), cur = 0;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) cur++;
            pre[i + 1] = cur;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if ((pre[i] - pre[j]) * 2 > i - j) ans++;
            }
        }
        return ans;
    }
};
