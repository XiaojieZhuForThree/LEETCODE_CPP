#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = size(languages);
        vector<vector<char>> matrix(m + 1, vector<char>(n + 1, false));
        for (int i = 0; i < m; i++) {
            for (auto& language : languages[i]) matrix[i + 1][language] = true;
        }
        vector<char> learn(m + 1, false);
        for (auto& friendship : friendships) {
            bool can = false;
            for (int i = 1; i <= n; i++) {
                if (matrix[friendship[0]][i] && matrix[friendship[1]][i]) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                learn[friendship[0]] = true;
                learn[friendship[1]] = true;
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            for (int j = 1; j <= m; j++) {
                if (learn[j] && !matrix[j][i]) cur++;
            }
            ans = std::min(ans, cur);
        }
        return ans;
    }
};