#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        std::unordered_set<int> pos;
        int ans = -10000, cur = 0;
        for (int i : nums) {
            if (pos.count(i)) continue;
            int cand = cur + i;
            ans = std::max(ans, cand);
            if (i <= 0) continue;
            pos.insert(i);
            cur += i;
        }
        return ans;
    }
};