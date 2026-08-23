#include <string>
using std::string;

class Solution {
public:
    bool sumGame(string num) {
        int n = size(num) / 2;
        int ls = 0, rs = 0, lq = 0, rq = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') lq++;
            else ls += (num[i] - '0');
            if (num[n + i] == '?') rq++;
            else rs += (num[n + i] - '0');
        }
        int ds = ls - rs, dq = lq - rq;
        if ((ds < 0 && dq <= 0) || (ds > 0 && dq >= 0)) return true;
        int d = abs(ds), q = abs(dq);
        if (d % 9 != 0) return true;
        int p = d / 9;
        if (p * 2 != q) return true;
        return false;
    }
};