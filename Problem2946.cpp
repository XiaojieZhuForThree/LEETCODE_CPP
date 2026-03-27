#include <vector>
using std::vector;

class Solution {
public:
    static bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = size(mat), n = size(mat[0]);
        k %= n;
        if (k == 0) return 1;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j + ((i % 2 == 0) ? n - k : k)) % n]) return false;
            }
        }
        return true;
    }
};