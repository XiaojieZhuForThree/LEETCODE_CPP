#include <cmath>

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (std::abs(x - z) > std::abs(y - z)) return 2;
        if (std::abs(x - z) < std::abs(y - z)) return 1;
        return 0;
    }
};