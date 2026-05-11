#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = size(nums) - 1; i >= 0; i--) {
            int j = nums[i];
            while (j) {
                ans.push_back(j % 10);
                j /= 10;
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};