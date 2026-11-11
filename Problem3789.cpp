#include <algorithm>
using std::min;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth >= cost1 + cost2) return (long long)(need1) * cost1 + (long long)(need2) * cost2;
        long long m = min(need1, need2), ans = m * costBoth, d1 = need1 - m, d2 = need2 - m;
        ans += d1 * min(cost1, costBoth) + d2 * min(cost2, costBoth);
        return ans;
    }
};
