#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for(int i = 0, n = size(stones); i < n; ++i) cnt[stones[i] % 3]++;
        int zero = cnt[0], one = cnt[1], two = cnt[2];
        if (min(one , two) == 0) return max(one , two) > 2 && (zero & 1);
        return zero % 2 == 0 || abs(two - one) > 2;
    }
};
