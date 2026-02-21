#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (yes(i)) ans++;
        }
        return ans;
    }
private:
    bool yes(int i) {
        unordered_set<int> pms = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int cnt = 0;
        while (i > 0) {
            cnt += i & 1;
            i >>= 1;
        }
        return pms.count(cnt);
    }
};