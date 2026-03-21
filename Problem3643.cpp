#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int h = x, l = x + k - 1;
        while (h < l) {
            for (int j = y; j < y + k; j++) {
                int tmp = grid[h][j];
                grid[h][j] = grid[l][j];
                grid[l][j] = tmp;
            }
            h++;
            l--;
        }
        return grid;
    }
};