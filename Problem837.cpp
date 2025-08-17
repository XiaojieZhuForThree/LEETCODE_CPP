#include <vector>
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
         if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        
        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double rs = 1.0;
        double ans = 0.0;
        
        for (int i = 1; i < n + 1; i++) {
            dp[i] = rs / maxPts;
            if (i < k) {
                rs += dp[i];
            } else {
                ans += dp[i];
            }
            if (i - maxPts >= 0) {
                rs -= dp[i - maxPts];
            }
        }
        return ans;
    }
};