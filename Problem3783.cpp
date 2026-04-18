#include <algorithm>

class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - helper(n));
    }
private:
    int helper(int n) {
        int ans = 0;
        while (n) {
            ans = ans * 10 + (n % 10);
            n /= 10;
        }
        return ans;
    }
};