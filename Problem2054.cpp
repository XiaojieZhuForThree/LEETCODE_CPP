#include <vector>
#include <map>
#include <algorithm>
using std::vector;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        std::map<int, int> m;
        std::sort(begin(events), end(events), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int cur = 0;
        for (auto& e : events) {
            cur = std::max(cur, e[2]);
            m[e[1]] = std::max(m[e[1]], cur);
        }
        int ans = 0;
        for (auto& e : events) {
            int cur = e[2];
            auto itr = m.lower_bound(e[0]);
            if (itr->first >= e[0]) itr--;
            if (itr->first < e[0]) cur += itr->second;
            ans = std::max(ans, cur);
        }
        return ans;
    }
};