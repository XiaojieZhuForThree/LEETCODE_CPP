#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        for (int i : nums) ans = std::min(i, ans);
        return ans;
    }
};
