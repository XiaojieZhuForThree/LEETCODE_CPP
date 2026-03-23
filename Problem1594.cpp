#include <vector>
using std::vector;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        long long mod = 1e9 + 7;
        vector<vector<long long>> ps(m, vector<long long>(n, LLONG_MIN)), ng(m, vector<long long>(n, LLONG_MAX));
        if (grid[0][0] == 0) {
            ps[0][0] = 0;
            ng[0][0] = 0;
        }
        else if (grid[0][0] > 0) ps[0][0] = grid[0][0];
        else ng[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ps[i][j] = 0;
                    ng[i][j] = 0;
                } else if (grid[i][j] > 0) {
                    if (i > 0) {
                        long long prep = ps[i - 1][j], pren = ng[i - 1][j];
                        if (prep == LLONG_MIN) ps[i][j] = std::max(ps[i][j], LLONG_MIN);
                        else ps[i][j] = std::max(ps[i][j], prep * grid[i][j]);
                        if (pren == LLONG_MAX) ng[i][j] = std::min(ng[i][j], LLONG_MAX);
                        else ng[i][j] = std::min(ng[i][j], pren * grid[i][j]);
                    }
                    if (j > 0) {
                        long long prep = ps[i][j - 1], pren = ng[i][j - 1];
                        if (prep == LLONG_MIN) ps[i][j] = std::max(ps[i][j], LLONG_MIN);
                        else ps[i][j] = std::max(ps[i][j], prep * grid[i][j]);
                        if (pren == LLONG_MAX) ng[i][j] = std::min(ng[i][j], LLONG_MAX);
                        else ng[i][j] = std::min(ng[i][j], pren * grid[i][j]);
                    }
                } else {
                    if (i > 0) {
                        long long prep = ps[i - 1][j], pren = ng[i - 1][j];
                        if (prep == LLONG_MIN) ng[i][j] = std::min(ng[i][j], LLONG_MAX);
                        else ng[i][j] = std::min(ng[i][j], prep * grid[i][j]);
                        if (pren == LLONG_MAX) ps[i][j] = std::max(ps[i][j], LLONG_MIN);
                        else ps[i][j] = std::max(ps[i][j], pren * grid[i][j]);
                    }
                    if (j > 0) {
                        long long prep = ps[i][j - 1], pren = ng[i][j - 1];
                        if (prep == LLONG_MIN) ng[i][j] = std::min(ng[i][j], LLONG_MAX);
                        else ng[i][j] = std::min(ng[i][j], prep * grid[i][j]);
                        if (pren == LLONG_MAX) ps[i][j] = std::max(ps[i][j], LLONG_MIN);
                        else ps[i][j] = std::max(ps[i][j], pren * grid[i][j]);
                    }
                }
            }
        }
        if (ps[m - 1][n - 1] != LLONG_MIN) return ps[m - 1][n - 1] % mod;
        return -1;
    }
};