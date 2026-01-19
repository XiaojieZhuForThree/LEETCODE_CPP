#include <vector>
using std::vector;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans = 0;
        for (auto& v : mat) {
            for (int i = 1; i < size(v); i++) v[i] += v[i - 1];
        }
        for (int i = 0; i < size(mat); i++) {
            for (int j = 0; j < size(mat[i]); j++) ans = std::max(ans, helper(mat, i, j, threshold));
        }
        return ans;
    }
private:
    int helper(vector<vector<int>>& mat, int i, int j, int t) {
        int l = 1, r = std::min(i + 1, j + 1);
        while (l < r) {
            int m = l + (r - l) / 2;
            if (yes(mat, i, j, m, t)) l = m + 1;
            else r = m;
        }
        if (!yes(mat, i, j, l, t)) l--;
        if (!yes(mat, i, j, l, t)) return 0;
        return l;

    }
    bool yes(vector<vector<int>>& mat, int i, int j, int m, int t) {
        long long s = 0;
        for (int k = 0; k < m; k++) s += mat[i - k][j] - (j - m >= 0 ? mat[i - k][j - m] : 0);
        return s <= t;
    }
};