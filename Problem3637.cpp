#include <vector>
using std::vector;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int l = 0, r = size(nums) - 1;
        while (l + 1 < size(nums) && nums[l + 1] > nums[l]) l++;
        while (r - 1 >= 0 && nums[r - 1] < nums[r]) r--;
        if (l == 0 || r == size(nums) - 1 || l >= r) return false;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] >= nums[i - 1]) return false;
        }
        return true;
    }
};