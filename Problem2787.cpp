#include <vector>
#include <cmath>

class Solution {
public:
    int MOD = (int)(1e9 + 7);
    int numberOfWays(int n, int x) {
        std::vector<int> v(n + 1, 0);
        v[0] = 1;
        for (int i = 1; pow(i, x) <= n; i++) {
            int t = pow(i, x), j = n - t;
            for (int k = j; k >= 0; k--) {
                v[k + t] += v[k];
                v[k + t] %= MOD;
            }
        }
        return v[n];
    }
};