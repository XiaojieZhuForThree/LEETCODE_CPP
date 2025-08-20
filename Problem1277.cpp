#include <vector>
using std::vector;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for (int i = 0; i < size(matrix); i++) {
            for (int j = 0; j < size(matrix[0]); j++) {
                if (!matrix[i][j]) continue;
                if (i == 0 || j == 0) ans++;
                else {
                    matrix[i][j] += std::min(matrix[i - 1][j - 1], std::min(matrix[i][j - 1], matrix[i - 1][j]));
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};