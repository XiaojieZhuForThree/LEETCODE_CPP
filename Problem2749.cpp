class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 == 0) return 0;
        long long base = num1;
        for (int i = 1; i <= 60; i++) {
            base -= num2;
            if (base < 0) return -1;
            if (base < i) return -1;
            if (helper(base) <= i) return i;
        }
        return -1;
    }
private:
    int helper(long long i) {
        int ans = 0;
        while (i > 0) {
            ans += i % 2;
            i /= 2;
        }
        return ans;
    }
};