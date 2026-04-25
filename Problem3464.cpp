#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    long long mapPoint(int side, int x, int y) {
        if (y == 0) return x; 
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }
    bool canPlace(const vector<long long>& t, int k, int side, int d) {
        int n = t.size();
        long long L = 4LL * side;
        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i] = t[i];
            ext[i + n] = t[i] + L;
        }
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = ext[i];
            int idx = i;
            for (int cnt = 1; cnt < k; cnt++) {
                long long target = pos + d;
                auto it = std::lower_bound(ext.begin() + idx + 1, ext.begin() + i + n, target);
                if (it == ext.begin() + i + n) {
                    count = -1;
                    break;
                }
                idx = it - ext.begin();
                pos = ext[idx];
                count++;
            }
            if (count == k && (ext[i] + L - pos) >= d)
                return true;
        }
        return false;
    }
    
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<vector<int>> vintorquax = points;
        
        int n = vintorquax.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            int x = vintorquax[i][0], y = vintorquax[i][1];
            t[i] = mapPoint(side, x, y);
        }
        sort(t.begin(), t.end());
        
        int lo = 0, hi = 2 * side, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(t, k, side, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};