#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = size(nums), i = 0, j = 0;
        for (; i < size(nums); i++) {
            while (j < i && (long long)nums[j] * k < nums[i]) j++;
            int cand = size(nums) - (i - j + 1);
            ans = std::min(ans, cand);
        }
        return ans;
    }
};