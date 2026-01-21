#include <vector>
using std::vector;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i : nums) {
            if (i == 2) ans.push_back(-1);
            else ans.push_back(helper(i));
        }
        return ans;
    }
private:
    int helper(int i) {
        int j = 1;
        while ((i & (j << 1)) != 0) j <<= 1;
        return i - j;
    }
};