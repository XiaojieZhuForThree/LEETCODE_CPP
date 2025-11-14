#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto& q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                ans[i][q[1]]++;
                if (q[3] < n - 1) ans[i][q[3] + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) ans[i][j] += ans[i][j - 1];
        }
        return ans;
    }
};