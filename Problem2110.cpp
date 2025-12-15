#include <vector>
using std::vector;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int i = 0;
        long long ans = 0;
        for (int j = 1; j <= size(prices); j++) {
            if (j == size(prices) || prices[j] != prices[j - 1] - 1) {
                int l = i - j;
                ans += ((long long)l * (l - 1)) / 2;
                i = j;
            }
        }
        return ans;
    }
};