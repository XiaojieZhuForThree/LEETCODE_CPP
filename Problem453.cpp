#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lo = INT_MAX / 2, x = 0;
        for (int i{}; int v : nums) {
            x += i++ * max(lo - v, 0);
            x += v - (lo = min(lo, v));
        }
        return x;
    }
};
