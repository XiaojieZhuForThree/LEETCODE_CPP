#include <vector>
using std::vector;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int r = 0;
        for (int l = 0; l < size(nums1); l++) {
            while (r < size(nums2) && nums2[r] < nums1[l]) r++;
            if (r < size(nums2) && nums1[l] == nums2[r]) return nums1[l];
        }
        return -1;
    }
};
