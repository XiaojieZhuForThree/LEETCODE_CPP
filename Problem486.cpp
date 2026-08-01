#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int s = sum(nums), b = helper(nums, 0, size(nums) - 1, s);
        return b >= s - b;
    }
private:
    int sum(vector<int>& n) {
        int ans = 0;
        for (int i : n) ans += i;
        return ans;
    }
    int helper(vector<int>& n, int l, int r, int s) {
        if (l > r) return 0;
        int val1 = n[l] + s - helper(n, l + 1, r, s - n[l]), val2 = n[r] + s - helper(n, l, r - 1, s - n[r]);
        return max(val1, val2);
    }
};
