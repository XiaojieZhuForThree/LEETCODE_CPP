#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = 0, cur = INT_MIN;
        for (int i : nums) {
            int a = i - k, b = i + k;
            if (cur < a) {
                ans++;
                cur = a;
            } else if (cur < b) {
                cur++;
                ans++;
            }
        }
        return ans;

    }
};