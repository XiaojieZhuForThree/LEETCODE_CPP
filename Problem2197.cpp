#include <vector>
#include <deque>
using std::vector;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        std::deque<int> q;
        for (int i : nums) {
            int cur = i;
            while (!q.empty()) {
                int j = q.back(), g = gcd(cur, j);
                if (g == 1) break;
                cur = g * (cur / g) * (j / g);
                q.pop_back();
            }
            q.push_back(cur);
        }
        vector<int> ans(begin(q), end(q));
        return ans;
    }
private:
    int gcd(int i, int j) {
        if (i < j) return gcd(j, i);
        if (i % j == 0) return j;
        return gcd(j, i % j);
    }
};