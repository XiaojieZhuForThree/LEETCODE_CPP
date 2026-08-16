#include <vector>
using std::vector;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> v(3, 0);
        for (int i : stones) v[i % 3]++;
        if (v[1] == 0 || v[2] == 0) {
            if (abs(v[1] - v[2]) <= 2) return false;
            return v[0] % 2 == 1;
        }
        return helper(v[0], v[1], v[2]) || helper(v[0], v[2], v[1]);
    }
private:
    bool helper(int a, int b, int c) {
        int p = std::min(b - 1, c);
        b -= (1 + p);
        c -= p;
        if (b == 0 && c == 0) return false;
        if (b == 0) return a % 2 == 0;
        if (b <= 1) return false;
        return a % 2 == 1;
    }
};

