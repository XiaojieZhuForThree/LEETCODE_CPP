#include <vector>
using std::vector;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = size(arr), MOD = 1e9 + 7;
        vector<long long> os(n + 1, 0), es(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                es[i + 1] = 1 + es[i];
                os[i + 1] = os[i];
            } else {
                os[i + 1] = 1 + es[i];
                es[i + 1] = os[i];
            }
        }
        int ans = 0;
        for (long long i : os) {
            ans += (i % MOD);
            ans %= MOD;
        }
        return ans;
    }
};
