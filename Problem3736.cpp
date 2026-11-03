#include <vector>
using std::vector;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, m = *max_element(begin(nums), end(nums));
        for (int i : nums) ans += m - i;
        return ans;
    }
};
