#include <vector>
#include <algorithm>
using std::vector;
using std::greater;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]), ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == 0) continue;
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        for (int i = 0; i < m; i++) {
            sort(begin(matrix[i]), end(matrix[i]), greater<int>());
            int cur = 0;
            for (int j = 0; j < n; j++) cur = std::max(cur, matrix[i][j] * (j + 1));
            ans = std::max(ans, cur);
        }
        return ans;
    }
};