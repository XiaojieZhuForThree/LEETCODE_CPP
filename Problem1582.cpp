#include <vector>
using std::vector;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = size(mat), n = size(mat[0]), ans = 0;
        vector<int> rs(m, 0), cs(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rs[i] += mat[i][j];
                cs[j] += mat[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                if (rs[i] == 1 && cs[j] == 1) ans++;
            }
        }
        return ans;

    }
};