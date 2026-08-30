#include <algorithm>
#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ma = 0, mi = 0, n = size(nums);
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[ma]) ma = i;
            if (nums[i] < nums[mi]) mi = i;
        }
        int i = min(ma, mi), j = max(ma, mi);
        int a = j + 1, b = n - i,  c = i + 1 + (n - j);
        return min(a, min(b, c));
    }
};
