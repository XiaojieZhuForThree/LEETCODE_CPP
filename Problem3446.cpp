#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = size(grid);
        for (int i = 1; i < n; i++) topSort(grid, i, n);
        for (int i = 0; i < n; i++) bottomSort(grid, i, n);
        return grid;
    }
private:
    void topSort(vector<vector<int>>& grid, int i, int n) {
        vector<int> v;
        for (int j = i; j < n; j++) v.push_back(grid[j - i][j]);
        sort(begin(v), end(v));
        for (int j = i; j < n; j++) grid[j - i][j] = v[j - i];
    }
    void bottomSort(vector<vector<int>>& grid, int i, int n) {
        vector<int> v;
        for (int j = i; j < n; j++) v.push_back(grid[j][j - i]);
        sort(begin(v), end(v));
        reverse(begin(v), end(v));
        for (int j = i; j < n; j++) grid[j][j - i] = v[j - i];
    }
};