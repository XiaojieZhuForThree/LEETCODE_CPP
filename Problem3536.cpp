class Solution {
public:
    int maxProduct(int n) {
        int f = 0, s = 0;
        while (n) {
            int c = n % 10;
            if (c > f) {
                s = f;
                f = c;
            } else if (c > s) s = c;
            n /= 10;
        }
        return f * s;
    }
};
