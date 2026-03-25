#include <vector>
using std::vector;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0, m = size(grid), n = size(grid[0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) sum += grid[i][j];
        }
        if (sum == 0 || sum % 2 == 1) return false;
        return byrow(grid, sum / 2) || bycol(grid, sum / 2);
    }
private:
    bool byrow(vector<vector<int>>& grid, long long t) {
        long long s = 0;
        for (int i = 0; i < size(grid) - 1; i++) {
            for (int j = 0; j < size(grid[0]); j++) s += grid[i][j];
            if (s == t) return true;
        }
        return false;
    }
    bool bycol(vector<vector<int>>& grid, long long t) {
        long long s = 0;
        for (int j = 0; j < size(grid[0]) - 1; j++) {
            for (int i = 0; i < size(grid); i++) s += grid[i][j];
            if (s == t) return true;
        }
        return false;
    }
};