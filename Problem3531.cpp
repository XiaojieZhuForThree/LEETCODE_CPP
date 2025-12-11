#include <vector>
using std::vector;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xl(n + 1, INT_MAX), xr(n + 1, 0), yu(n + 1, 0), yd(n + 1, INT_MAX);
        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            xl[y] = std::min(xl[y], x);
            xr[y] = std::max(xr[y], x);
            yu[x] = std::max(yu[x], y);
            yd[x] = std::min(yd[x], y);
        }
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (xl[y] < x && xr[y] > x && yu[x] > y && yd[x] < y) ans++;
        }
        return ans;
    }
};