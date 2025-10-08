#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions), end(potions));
        vector<int> ans;
        for (int i : spells) ans.push_back(helper(i, potions, success));
        return ans;
    }
private:
    int helper(int i, vector<int>& p, long long success) {
        long long j = success / i, n = size(p);
        if (success % i) j++;
        if (p[n - 1] < j) return 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (p[m] < j) l = m + 1;
            else r = m;
        }
        return n - l;
    }
};