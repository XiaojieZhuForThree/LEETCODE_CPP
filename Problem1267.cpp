#include <vector>
using std::vector;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && (r[i] > 1 || c[j] > 1)) ans++;
            }
        }
        return ans;
    }
};
