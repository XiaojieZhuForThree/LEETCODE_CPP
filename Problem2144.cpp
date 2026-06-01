#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int ans = 0;
        for (int i = size(cost) - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i - 1 >= 0) ans += cost[i - 1];
        }
        return ans;
    }
};