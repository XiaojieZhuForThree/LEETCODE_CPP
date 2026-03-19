#include <vector>
using std::vector;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = size(grid), n = size(grid[0]), ans = 0;
        vector<vector<int>> x(m, vector<int>(n, 0)), y(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    x[i][j] = x[i][j - 1];
                    y[i][j] = y[i][j - 1];
                }
                x[i][j] += (grid[i][j] == 'X');
                y[i][j] += (grid[i][j] == 'Y');
            }
        }
        for (int j = 0; j < n; j++) {
            int cx = 0, cy = 0;
            for (int i = 0; i < m; i++) {
                cx += x[i][j];
                cy += y[i][j];
                if (cx == cy && cx >= 1) ans++;
            }
        }
        return ans;
    }
};