#include <vector>
using std::vector;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = size(fruits), l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (fruits[m][0] < startPos) l = m + 1;
            else r = m;
        }
        if (fruits[l][0] > startPos) l--;
        int b = l, t = 0, ans = 0;
        r = l + 1;
        while (r < n && (fruits[r][0] - startPos) * 2 <= k) {
            t += fruits[r][1];
            r++;
        }
        r--;
        ans = t;
        while (l >= 0 && startPos - fruits[l][0] <= k) {
            t += fruits[l][1];
            while (r >= l && (fruits[r][0] - startPos) * 2 + (startPos - fruits[l][0]) > k) {
                t -= fruits[r][1];
                r--;
            }
            l--;
            ans = std::max(ans, t);
        }
        l = b;
        r = l + 1;
        t = 0;
        while (l >= 0 && (startPos - fruits[l][0]) * 2 <= k) {
            t += fruits[l][1];
            l--;
        }
        l++;
        ans = std::max(ans, t);
        while (r < n && (fruits[r][0] - startPos) <= k) {
            t += fruits[r][1];
            while (l <= r && (startPos - fruits[l][0]) * 2 + (fruits[r][0] - startPos) > k) {
                t -= fruits[l][1];
                l++;
            }
            r++;
            ans = std::max(ans, t);
        }
        return ans;
    }
};