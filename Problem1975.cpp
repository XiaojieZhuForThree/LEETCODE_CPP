#include <vector>
using std::vector;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long pos = 0, neg = 0;
        int cn = 0, sp = INT_MAX, bn = INT_MIN;
        for (int i = 0; i < size(matrix); i++) {
            for (int j = 0; j < size(matrix[0]); j++) {
                if (matrix[i][j] < 0) {
                    neg += matrix[i][j];
                    bn = std::max(bn, matrix[i][j]);
                    cn++;
                } else {
                    pos += matrix[i][j];
                    sp = std::min(sp, matrix[i][j]);
                }
            }
        }
        if (cn % 2 == 0) return pos - neg;
        return pos - neg - 2 * std::min(abs(sp), abs(bn));
    }
};