#include <vector>
using std::vector;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (auto &i : points)
            for (auto &j : points)
                for (auto &k : points)
            ans = std::max(ans, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return ans;
    }
};