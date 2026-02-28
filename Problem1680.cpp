class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            ans <<= helper(i);
            ans += i;
            ans %= mod;
        }
        return ans;
    }
private:
    int helper(int i) {
        int ans = 0;
        while (i) {
            ans++;
            i >>= 1;
        }
        return ans;
    }
};