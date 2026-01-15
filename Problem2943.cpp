#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = maxGap(hBars);
        int v = maxGap(vBars);
        int side = std::min(h, v);
        return side * side;
    }
private:
    int maxGap(vector<int>& v) {
        sort(begin(v), end(v));
        int best = 1, cur = 1;
        for (int i = 1; i < size(v); i++) {
            if (v[i] == v[i-1] + 1) cur++;
            else cur = 1;
            best = std::max(best, cur);
        }
        return best + 1;
    }
};
