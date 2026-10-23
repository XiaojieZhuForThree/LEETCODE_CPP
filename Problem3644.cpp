#include <vector>
using std::vector;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = size(nums), ans = -1;
        vector<int> checked(n, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) continue;
            if (checked[i] != -1) continue;
            checked[i] = 1;
            int j = nums[i], cur = j;
            while (j != i) {
                checked[j] = 1;
                cur &= nums[j];
                j = nums[j];
            }
            if (ans != -1) ans &= cur;
            else ans = cur;
        }
        return ans == -1 ? 0 : ans;
    }
};
