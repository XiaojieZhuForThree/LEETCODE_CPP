class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0, b = 1, c = n;
        while (c) {
            a += c % 10;
            b *= c % 10;
            c /= 10;
        }
        return n % (a + b) == 0;
    }
};
