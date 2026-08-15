#include <vector>
using std::vector;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cur = 0, n = size(nums);
        for (int i : nums) cur ^= i;
        if (cur == 0) return helper(nums);
        return n;
    }

private:
    int helper(vector<int>& nums) {
        int n = size(nums);
        for (int i : nums) {
            if (i != 0) return n - 1;
        }
        return 0;
    }
};