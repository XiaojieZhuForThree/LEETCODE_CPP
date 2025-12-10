#include <vector>
using std::vector;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for (int i = 1; i < size(complexity); i++) {
            if (complexity[i] <= complexity[0]) return 0;
        }
        return fac(size(complexity) - 1);
    }
private:
    int fac(int i) {
        long long ans = 1;
        for (int j = 1; j <= i; j++) {
            ans *= j;
            ans %= 1000000007;
        }
        return ans;
    }
};