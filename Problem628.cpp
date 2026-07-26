#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> u, d;
        for (int i : nums) {
            if (i >= 0) u.push_back(i);
            else d.push_back(i);
        }
        sort(begin(u), end(u));
        sort(begin(d), end(d));
        int ans = INT_MIN, m = size(u), n = size(d);
        if (n == 0) ans = u[m - 1] * u[m - 2] * u[m - 3];
        else if (n == 1) {
            if (m == 2) ans = u[m - 1] * u[m - 2] * d[n - 1];
            else ans = u[m - 1] * u[m - 2] * u[m - 3];
        } else if (n == 2) {
            if (m <= 2) ans = d[n - 1] * d[n - 2] * u[m - 1];
            else ans = std::max(d[0] * d[1] * u[m - 1], u[m - 1] * u[m - 2] * u[m - 3]);
        } else {
            if (m == 0) ans = d[n - 1] * d[n - 2] * d[n - 3];
            else if (m <= 2) ans = d[0] * d[1] * u[m - 1];
            else ans = std::max(d[0] * d[1] * u[m - 1], u[m - 1] * u[m - 2] * u[m - 3]);
        }
        return ans;
    }
};
