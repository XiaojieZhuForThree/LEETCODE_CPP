#include <vector>
#include <queue>
using std::vector;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int t = size(nums), n = t / 3;
        long long s = 0;
        std::priority_queue<int> q1;
        std::priority_queue<int, vector<int>, std::greater<int>> q2;
        vector<long long> dp1(t, 0), dp2(t, 0);
        for (int i = 0; i < 2 * n; i++) {
            s += nums[i];
            q1.push(nums[i]);
            if (size(q1) > n) {
                int cur = q1.top();
                s -= cur;
                q1.pop();
            }
            dp1[i] = s;
        }
        s = 0;
        for (int i = t - 1; i >= n; i--) {
            s += nums[i];
            q2.push(nums[i]);
            if (size(q2) > n) {
                int cur = q2.top();
                s -= cur;
                q2.pop();
            }
            dp2[i] = s;
        }
        long long ans = dp1[n - 1] - dp2[n];
        for (int i = n; i <= 2 * n; i++) ans = std::min(ans, dp1[i - 1] - dp2[i]);
        return ans;
    }
};