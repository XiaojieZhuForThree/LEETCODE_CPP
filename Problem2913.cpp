#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s;
        for (int i = 0; i < size(nums); i++) {
            s.clear();
            for (int j = i; j >= 0; j--) {
                s.insert(nums[j]);
                ans += size(s) * size(s);
            }
        }
        return ans;
    }
};
