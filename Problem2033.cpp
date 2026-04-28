#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& r : grid) {
            for (int i : r) v.push_back(i);
        }
        sort(begin(v), end(v));
        if (!yes(v, x)) return -1;
        return helper(v, x);
    }
private:
    bool yes(vector<int>& v, int x) {
        for (int i = 1; i < size(v); i++) {
            if ((v[i] - v[i - 1]) % x) return false;
        }
        return true;
    }
    int helper(vector<int>& v, int x) {
        int m = size(v) / 2, cur = v[m], ans = 0;
        for (int i : v) ans += abs(i - cur) / x;
        return ans;
    }
};