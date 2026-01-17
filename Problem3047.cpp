#include <vector>
using std::vector;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0, n = size(bottomLeft);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) ans = std::max(ans, helper(bottomLeft, topRight, i, j));
        }
        return ans;
    }
private:
    long long helper(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight, int i, int j) {
        int lx1 = bottomLeft[i][0], ly1 = bottomLeft[i][1], ux1 = topRight[i][0], uy1 = topRight[i][1];
        int lx2 = bottomLeft[j][0], ly2 = bottomLeft[j][1], ux2 = topRight[j][0], uy2 = topRight[j][1];
        if (ly2 >= uy1 || uy2 <= ly1) return 0;
        if (lx2 >= ux1 || ux2 <= lx1) return 0;
        long long lx = std::max(lx1, lx2), ly = std::max(ly1, ly2);
        long long ux = std::min(ux1, ux2), uy = std::min(uy1, uy2);
        long long s = std::min(ux - lx, uy - ly);
        return s * s;

    }
};