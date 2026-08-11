#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = size(nums);
        unordered_set<int> seen(begin(nums), end(nums));
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) sum += nums[i];
            else break;
        }
        while (seen.count(sum)) sum++;
        return sum;
    }
};
