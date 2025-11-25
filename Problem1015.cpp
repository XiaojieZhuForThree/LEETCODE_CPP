class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int cur = 1, ans = 1;
        while (cur % k != 0) {
            ans++;
            cur = (cur % k) * 10 + 1;
        }
        return ans;
    }
};