#include <vector>
using std::vector;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), l = n - 1, r = 0, u = m - 1, d = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                l = std::min(l, j);
                r = std::max(r, j);
                u = std::min(u, i);
                d = std::max(d, i);
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
};