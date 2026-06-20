#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int pass(vector<vector<int>>& r) {
        int res = 0;
        for (int i = 0; i < r.size() - 1; ++i) {
            auto h1 = r[i][1], h2 = r[i + 1][1];
            auto h = h1 + abs(r[i + 1][0] - r[i][0]);
            if (h > h2)
                h = h2 + (h - h2) / 2;
            res = max(res, h);
            r[i + 1][1] = min(h, h2);
        }
        return res;
    }
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.insert(r.end(), {{1, 0}, {n, n - 1}});
        sort(begin(r), end(r));
        pass(r);
        reverse(begin(r), end(r));
        return pass(r);
    }
};
