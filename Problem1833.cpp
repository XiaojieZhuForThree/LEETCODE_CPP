#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int ans = 0;
        for (int i : costs) {
            if (i <= coins) {
                ans++;
                coins -= i;
            }
        }
        return ans;
    }
};
