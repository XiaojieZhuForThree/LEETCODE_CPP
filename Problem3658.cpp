#include <numeric>
using std::gcd;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            odd += (i - 1) * 2 + 1;
            even += i * 2;
        }
        return gcd(odd, even);
    }
};
