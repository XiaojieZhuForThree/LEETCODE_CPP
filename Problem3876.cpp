#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(begin(nums1), end(nums1));
        int b = nums1[0], o = (b % 2 == 1);
        for (int i : nums1) {
            if (i % 2 != b % 2 && o == 0) return false;
            o += (i % 2 == 1);
        }
        return true;
    }
};
