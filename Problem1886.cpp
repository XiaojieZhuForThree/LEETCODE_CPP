#include <vector>
using std::vector;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (eq(mat, target)) return true;
        for (int i = 0; i < 3; i++) {
            mat = rot(mat);
            if (eq(mat, target)) return true;
        }
        return false;
    }
private:
    bool eq(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        int n = size(m1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m1[i][j] != m2[i][j]) return false;
            }
        }
        return true;
    }
    vector<vector<int>> rot(vector<vector<int>>& m) {
        int n = size(m);
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) ans[i][j] = m[n - 1 - j][i];
        }
        return ans;
    }
};
