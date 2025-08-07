#include <vector>
using std::vector;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = size(fruits);
        vector<vector<int>> dp1(n, vector<int>(n, 0));
        vector<vector<int>> dp2(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans + fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<int> dx = {1, 0, -1};
        dp1[0][n - 1] = fruits[0][n - 1];
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i + j >= n - 1) {
                    for (int d = 0; d < 3; d++) {
                        int y = i - 1;
                        int x = j - dx[d];
                        if (x + y >= n - 1 && x >= 0 && y >= 0 && x >= y && x < n && y < n) {
                            dp1[i][j] = std::max(dp1[i][j], dp1[y][x] + fruits[i][j]);
                        }
                    }
                }
            }
        }
        vector<int> dy = {1, -1, 0};
        dp2[n - 1][0] = fruits[n - 1][0];
        for (int j = 1; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (i + j >= n - 1) {
                    for (int d = 0; d < 3; d++) {
                        int y = i - dy[d];
                        int x = j - 1;
                        if (x + y >= n - 1 && x >= 0 && y >= 0 && x <= y && x < n && y < n) dp2[i][j] = std::max(dp2[i][j], dp2[y][x] + fruits[i][j]);
                    }
                }
            }
        }
        return ans + dp1[n - 1][n - 1] + dp2[n - 1][n - 1];
    }
};