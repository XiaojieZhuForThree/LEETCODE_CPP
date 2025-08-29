class Solution {
public:
    long long flowerGame(int n, int m) {
        int o1 = n / 2, e1 = n / 2, o2 = m / 2, e2 = m / 2;
        if (n % 2) o1++;
        if (m % 2) o2++;
        return (long long)o1 * e2 + (long long)e1 * o2;
    }
};