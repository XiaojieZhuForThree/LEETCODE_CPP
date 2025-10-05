#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) dfs(heights, i, 0, pacific);
        for(int j = 0; j < n; j++) dfs(heights, 0, j, pacific);
        
        for(int i = 0; i < m; i++) dfs(heights, i, n-1, atlantic);
        for(int j = 0; j < n; j++) dfs(heights, m-1, j, atlantic);
        
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        visited[i][j] = true;
        
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for(auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && 
               !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, ni, nj, visited);
            }
        }
    }
};