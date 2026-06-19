#include <vector>
using std::vector;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for (int i : gain) {
            cur += i;
            ans = std::max(ans, cur);
        }
        return ans;
    }
};
