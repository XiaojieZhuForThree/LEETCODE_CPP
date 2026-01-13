#include <vector>
using std::vector;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long l = 0, r = 1e14;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (check(squares, m)) l = m + 1;
            else r = m;
        }
        return l / 100000.0;
    }
private:
    bool check(vector<vector<int>>& squares, long long m) {
        long long b = 0, u = 0;
        for (auto& s : squares) {
            long long y = s[1], l = s[2];
            long long bot = y * 100000, top = bot + l * 100000;
            if (top <= m) b += l * l * 100000;
            else if (bot >= m) u += l * l * 100000;
            else {
                u += (top - m) * l;
                b += (m - bot) * l;
            }
        }
        return b < u;
    }
};