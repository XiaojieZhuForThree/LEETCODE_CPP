#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        for (int i = -n; i <= n; i++) {
            for (int j = -n; j <= n; j++) {
                int cur = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (img1[x][y] == 0) continue;
                        int nx = x + i, ny = y + j;
                        if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
                        if (img2[x + i][y + j] == 1) cur++;
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;  
    }
};
