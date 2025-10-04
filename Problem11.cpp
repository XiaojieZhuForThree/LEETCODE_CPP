#include <vector>
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = size(height) - 1, ans = 0;
        while (l < r) {
            ans = std::max(ans, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};