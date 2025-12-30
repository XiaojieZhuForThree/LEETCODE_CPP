#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), ans = 0;
        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (yes(grid, i, j)) ans++;
            }
        }
        return ans;
    }
private:
    bool yes(vector<vector<int>>& grid, int i, int j) {
        int s = 0;
        std::unordered_set<int> seen;
        for (int k = 0; k < 3; k++) {
            for (int t = 0; t < 3; t++) {
                int cur = grid[i + k][j + t];
                if (cur < 1 || cur > 9 || seen.count(cur)) return false;
                seen.insert(cur);
            }
        }
        for (int k = 0; k < 3; k++) s += grid[i][j + k];
        for (int k = 0; k < 3; k++) {
            int cand = 0;
            for (int t = 0; t < 3; t++) cand += grid[i + k][j + t];
            if (cand != s) return false;
        }
        for (int k = 0; k < 3; k++) {
            int cand = 0;
            for (int t = 0; t < 3; t++) cand += grid[i + t][j + k];
            if (cand != s) return false;
        }
        int cand = 0;
        for (int k = 0; k < 3; k++) cand += grid[i + k][j + k];
        if (cand != s) return false;
        cand = 0;
        for (int k = 0; k < 3; k++) cand += grid[i + 2 - k][j + k];
        if (cand != s) return false;
        return true;
    }
};