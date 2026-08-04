#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> ans;
        for (int i = 1; i < size(nums); i++) {
            for (int j = nums[i - 1] + 1; j < nums[i]; j++) ans.push_back(j);
        }
        return ans;
    }
};
