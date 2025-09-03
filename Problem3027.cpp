#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        std::sort(points.begin(), points.end(),
                  [](const vector<int>& x, const vector<int>& y) {
                      if (x[0] != y[0]) {
                          return x[0] < y[0];
                      }
                      return x[1] > y[1];
                  });
        for (int j = n - 1; j >= 0; j--) {
            int x = points[j][0];
            int y = points[j][1];
            int mn = 1e9;
            for (int i = j - 1; i >= 0; i--) {
                int xx = points[i][0];
                int yy = points[i][1];
                if (yy >= mn || yy < y) {
                    continue;
                }
                ans++;
                mn = yy;
            }
        }
        return ans;
    }
};