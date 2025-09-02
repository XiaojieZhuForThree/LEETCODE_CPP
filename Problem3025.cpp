#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = size(points), ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                auto& a = points[i], b = points[j];
                if (a[1] < b[1]) continue;
                bool yes = true;
                int l = a[0], r = b[0], d = b[1], u = a[1];
                for (int k = i + 1; k < j; k++) {
                    auto& c = points[k];
                    if (c[0] >= l && c[0] <= r && c[1] >= d && c[1] <= u) yes = false;
                }
                ans += yes;
            }
        }
        return ans;
    }
};