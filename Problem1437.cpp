#include <vector>
 using std::vector;
 
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == 0) continue;
            if (prev == -1 || i - prev > k) prev = i;
            else return false;
        }
        return true;
    }
};