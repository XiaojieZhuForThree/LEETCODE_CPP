#include <vector>
using std::vector;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = size(mat), n = size(mat[0]);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) continue;
                mat[i][j] += j > 0 ? mat[i][j - 1] : 0;
                int cur = mat[i][j];
                for (int k = i; k >= 0 && mat[k][j] > 0; k--) {
                    cur = std::min(cur, mat[k][j]);
                    ans += cur;
                }
            }
        }
        return ans;
    }
};