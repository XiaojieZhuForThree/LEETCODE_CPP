#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using std::vector;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        std::priority_queue<std::pair<long long, int>, vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
        std::priority_queue<int, vector<int>, std::greater<int>> pool;
        for (int i = 0; i < n; i++) pool.push(i);
        vector<int> cnt(n, 0);
        int mx = 0, ans = 0;
        for (auto& m : meetings) {
            int dur = m[1] - m[0];
            int cC = 0, cV = 0;
            while (!pq.empty() && pq.top().first <= m[0]) {
                pool.push(pq.top().second);
                pq.pop();
            }
            if (pq.empty() || !pool.empty()) {
                int cur = pool.top();
                pool.pop();
                cnt[cur]++;
                cC = cnt[cur];
                cV = cur;
                pq.push({m[1], cur});
            } else {
                auto cand = pq.top();
                pq.pop();
                cnt[cand.second]++;
                cC = cnt[cand.second];
                cV = cand.second;
                pq.push({(long long)(cand.first) + dur, cand.second});
            }
            if (cC > mx || (cC == mx && cV < ans)) {
                mx = cC;
                ans = cV;
            }
        }
        return ans;
    }
};