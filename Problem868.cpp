#include <algorithm>
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cur = -1, cnt = 0;
        while (n) {
            int l = n & 1;
            if (l == 1) {
                if (cur != -1) ans = std::max(ans, cnt - cur);
                cur = cnt;
            }
            n >>= 1;
            cnt++;
        }
        return ans;
    }
};