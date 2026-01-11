#include <vector>
using std::vector;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;
                v[i][j] = 1 + (j > 0 ? v[i][j - 1] : 0);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) continue;
                int cur = v[i][j], w = v[i][j];
                for (int k = i - 1; k >= 0 && v[k][j] > 0; k--) {
                    w = std::min(w, v[k][j]);
                    cur = std::max(cur, w * (i - k + 1));
                }
                ans = std::max(ans, cur);
            }
        }
        return ans;
    }
};