class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long dig = 1000;

        while (dig <= n) {
            ans += n - dig + 1;
            dig = dig * 1000;
        }

        return ans;
    }
};
