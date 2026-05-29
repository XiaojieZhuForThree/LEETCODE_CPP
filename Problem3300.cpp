#include <vector>
using std::vector;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int i : nums) {
            int cur = 0;
            while (i) {
                cur += (i % 10);
                i /= 10;
            }
            ans = std::min(ans, cur);
        }
        return ans;
    }
};