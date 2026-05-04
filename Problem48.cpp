#include <vector>
using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = size(matrix);
        helper(matrix, 0, n - 1);
        return;
    }
private:
    void helper(vector<vector<int>>& m, int l, int r) {
        if (l >= r) return;
        int diff = r - l;
        for (int i = 0; i < diff; i++) {
            int val1 = m[l][l + i], val2 = m[l + i][r];
            int val3 = m[r][r - i], val4 = m[r - i][l];
            m[l + i][r] = val1;
            m[r][r - i] = val2;
            m[r - i][l] = val3;
            m[l][l + i] = val4;
        }
        helper(m, l + 1, r - 1);
    }
};
