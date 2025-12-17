#include <vector>
using std::vector;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;

        vector<long long> dp_prev(n, 0), dp_cur(n, 0);

        for (int t = 1; t <= k; t++) {
            long long best_buy = -prices[0];
            long long best_short = prices[0];
            dp_cur[0] = 0;

            for (int i = 1; i < n; i++) {
                long long a = dp_cur[i - 1];
                long long b = best_buy + prices[i];
                long long c = best_short - prices[i];

                dp_cur[i] = std::max({a, b, c});

                best_buy = std::max(best_buy, dp_prev[i - 1] - prices[i]);
                best_short = std::max(best_short, dp_prev[i - 1] + prices[i]);
            }

            swap(dp_prev, dp_cur);
        }
        return dp_prev[n - 1];
    }
};