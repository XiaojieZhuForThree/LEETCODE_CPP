#include <vector>
using std::vector;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));
        for (auto& v : walls) g[v[0]][v[1]] = 1;
        for (auto& v : guards) g[v[0]][v[1]] = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 2) {
                    for (int k = i + 1; k < m && (g[k][j] == 0 || g[k][j] == 3); k++) g[k][j] = 3;
                    for (int k = i - 1; k >= 0 && (g[k][j] == 0 || g[k][j] == 3); k--) g[k][j] = 3;
                    for (int k = j + 1; k < n && (g[i][k] == 0 || g[i][k] == 3); k++) g[i][k] = 3;
                    for (int k = j - 1; k >= 0 && (g[i][k] == 0 || g[i][k] == 3); k--) g[i][k] = 3;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};