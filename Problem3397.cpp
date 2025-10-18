#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0;
        sort(begin(nums), end(nums));
        for(int i = 0, last = INT_MIN; i < size(nums); i++){
            int mn = nums[i] - k;
            int mx = nums[i] + k;
            if(last < mn) {
                last = mn;
                ans++;
            }
            else if (last < mx) {
                last = last + 1;
                ans++;
            }
        }
        return ans;        
    }
};