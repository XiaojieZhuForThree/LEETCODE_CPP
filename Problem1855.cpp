#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    static int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1), n2 = size(nums2), ans = 0;
        for(int i = 0, j = 0; i < n1 && j < n2; ){
            if (i <= j && nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            }
            else if ( i <= j) i++;
            else j++;
        }
        return ans;
    }
};
