#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> m;
        for (; r < size(nums); r++) {
            m[nums[r]]++;
            while (m[nums[r]] > k) {
                m[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
