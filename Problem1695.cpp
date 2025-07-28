#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, l = 0, cur = 0;
        std::unordered_map<int, int> m;
        for (int r = 0; r < size(nums); r++) {
            m[nums[r]]++;
            cur += nums[r];
            while (m[nums[r]] > 1 && l < r) {
                m[nums[l]]--;
                cur -= nums[l++];
            }
            ans = std::max(ans, cur);
        }
        return ans;
    }
};