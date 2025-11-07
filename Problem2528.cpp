#include <vector>
using std::vector;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = size(stations);
        vector<long long> v(n + 1);
        for (int i = 0; i < n; i++) {
            v[std::max(0, i - r)] += stations[i];
            v[std::min(i + r + 1, n)] -= stations[i];
        }
        long long l = 0, h = LLONG_MAX;
        while (l < h) {
            long long m = l + (h - l) / 2;
            if (yes(v, n, m, k, r)) l = m + 1;
            else h = m;
        }
        return yes(v, n, l, k, r) ? l : l - 1;
    }
private:
    bool yes(vector<long long>& v, int n, long long m, int k, int r) {
        long long acc = 0, cur = 0;
        vector<long long> vv(begin(v), end(v));
        for (int i = 0; i < n; i++) {
            cur += vv[i];
            if (cur >= m) continue;
            acc += m - cur;
            if (acc > k) return false;
            vv[std::min(i + 2 * r + 1, n)] -= m - cur;
            cur = m;
        }
        return true;
    }
};