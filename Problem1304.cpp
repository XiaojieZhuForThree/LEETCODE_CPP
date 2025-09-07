#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        int l = 0, r = n - 1, cur = 1;
        while (l < r) {
            ans[l++] = cur;
            ans[r--] = -cur;
            cur++;
        }
        return ans;
    }
};