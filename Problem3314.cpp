#include <vector>
using std::vector;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i : nums) {
            if (i == 2) ans.push_back(-1);
            else {
                for (int j = 1; j <= i; j++) {
                    if ((j | (j + 1)) == i) {
                        ans.push_back(j);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};