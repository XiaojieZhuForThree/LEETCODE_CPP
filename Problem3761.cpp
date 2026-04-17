#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> m;
        for (int i = size(nums) - 1; i >= 0; i--) {
            int j = reverse(nums[i]);
            if (m.count(j)) {
                int cur = abs(i - m[j]);
                if (ans == -1 || ans > cur) ans = cur;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
private:
    int reverse(int i) {
        int ans = 0;
        while (i > 0) {
            ans = ans * 10 + (i % 10);
            i /= 10;
        }
        return ans;
    }
};
