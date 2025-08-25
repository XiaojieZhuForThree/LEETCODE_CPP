#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0, m = size(mat), n = size(mat[0]);
        bool ur = true;
        for (int k = 0; k < m * n; k++) {
            ans.push_back(mat[i][j]);
            if (ur) {
                if (i - 1 >= 0 && j + 1 < n) {
                    i--;
                    j++;
                } else if (j + 1 < n) {
                    j++;
                    ur = false;
                } else {
                    i++;
                    ur = false;
                }
            } else {
                if (i + 1 < m && j - 1 >= 0) {
                    i++;
                    j--;
                } else if (i + 1 < m) {
                    i++;
                    ur = true;
                } else {
                    j++;
                    ur = true;
                }
            }
        }
        return ans;
    }
};