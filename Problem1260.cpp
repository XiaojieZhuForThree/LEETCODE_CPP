#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for (int i = 0; i < k; i++) process(grid);
        return grid;
    }
private:
    void process(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]);
        vector<int> reserve;
        for (int i = 0; i < m; i++) reserve.push_back(grid[i][n - 1]);
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j > 0; j--) grid[i][j] = grid[i][j - 1];
        }
        for (int i = 0; i < m - 1; i++) grid[i + 1][0] = reserve[i];
        grid[0][0] = reserve[m - 1];
    }
};