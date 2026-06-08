#include <vector>
using std::vector;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = size(nums), cur = 0;
        vector<int> ans(n, 0);
        for (int i : nums) {
            if (i < pivot) ans[cur++] = i;
        }
        for (int i : nums) {
            if (i == pivot) ans[cur++] = i;
        }
        for (int i : nums) {
            if (i > pivot) ans[cur++] = i;
        }
        return ans;
    }
};
