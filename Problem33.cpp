#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};
