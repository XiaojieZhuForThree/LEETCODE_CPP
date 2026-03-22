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
        int n = size(m), k = n / 2;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) ans[i][j] = m[i][j];
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; i + j < n - i; j++) {
                ans[i][i + j] = m[n - 1 - i - j][i];
                ans[i + j][n - 1 - i] = m[i][i + j];
                ans[n - 1 - i][n - 1 - i - j] = m[i + j][n - 1 - i];
                ans[n - 1 - i - j][i] = m[n - 1 - i][n - 1 - i - j];
            }
        }
        return ans;
    }
};