#include <vector>
using std::vector;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1 {nums[0]}, v2 {nums[1]}, ans;
        for (int i = 2; i < size(nums); i++) {
            if (v1[size(v1) - 1] > v2[size(v2) - 1]) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        for (int i : v1) ans.push_back(i);
        for (int i : v2) ans.push_back(i);
        return ans;
    }
};
