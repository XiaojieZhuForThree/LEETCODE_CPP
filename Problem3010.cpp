#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        vector<int> v;
        for (int i = 1; i < size(nums); i++) v.push_back(nums[i]);
        sort(begin(v), end(v));
        return ans + v[0] + v[1];
    }
};