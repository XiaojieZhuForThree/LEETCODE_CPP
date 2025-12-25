#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(rbegin(happiness), rend(happiness));
        for (int i = 0; i < k; i++) ans += std::max(happiness[i] - i, 0);
        return ans;
    }
};