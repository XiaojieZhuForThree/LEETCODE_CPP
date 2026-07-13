#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) helper(ans, i, low, high);
        sort(begin(ans), end(ans));
        return ans;
    }
private:
    void helper(vector<int>& ans, long long i, int l, int h) {
        if (i >= l && i <= h) ans.push_back(i);
        int base = i % 10;
        if (base + 1 > 9) return;
        helper(ans, i * 10 + base + 1, l, h);
    }
};
