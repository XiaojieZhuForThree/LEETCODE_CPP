class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            if (yes(i, t)) return i;
        }
        return -1;
    }

private:
    bool yes(int i, int t) {
        int cur = 1;
        while (i) {
            cur *= (i % 10);
            i /= 10;
        }
        return cur % t == 0;
    }
};
