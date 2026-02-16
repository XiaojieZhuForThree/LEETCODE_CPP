#include <deque>
using std::deque;

class Solution {
public:
    int reverseBits(int n) {
        deque<int> stk;
        while (n > 0) {
            stk.push_back(n % 2);
            n >>= 1;
        }
        int ans = 0;
        while (size(stk) < 32) stk.push_back(0);
        while (!stk.empty()) {
            ans = ans * 2 + stk.front();
            stk.pop_front();
        }
        return ans;
    }
};