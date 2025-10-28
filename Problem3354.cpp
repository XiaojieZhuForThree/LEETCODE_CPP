#include <vector>
using std::vector;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != 0) continue;
            ans += helper(nums, i, true) + helper(nums, i, false);
        }
        return ans;
    }
private:
    bool helper(vector<int>& nums, int i, bool isleft) {
        vector<int> copy(nums);
        while (i >= 0 && i < size(copy)) {
            if (copy[i] == 0) {
                if (isleft) i--;
                else i++;
            } else {
                copy[i]--;
                isleft = !isleft;
                if (isleft) i--;
                else i++;
            }
        }
        for (int i : copy) {
            if (i > 0) return false;
        }
        return true;
    }
};