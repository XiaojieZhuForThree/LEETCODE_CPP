#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;

class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations) {
        std::sort(begin(nums), end(nums));
        std::unordered_map<int, int> count;
        int res = 0, i = 0, j = 0, n = size(nums);
        for (int a : nums) {
            while (j < n && nums[j] <= a + k) {
                count[nums[j]]++;
                j++;
            }
            while (i < n && nums[i] < a - k) {
                count[nums[i]]--;
                i++;
            }
            int cur = std::min(j - i, count[a] + numOperations);
            res = std::max(res, cur);
        }
        for (int i = 0, j = 0; j < n; j++) {
            while (nums[i] + k + k < nums[j]) i++;
            res = std::max(res, std::min(j - i + 1, numOperations));
        }
        return res;
    }
};