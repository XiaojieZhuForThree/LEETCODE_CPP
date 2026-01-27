#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        auto m = process(n, edges);
        return dijkstra(m, 0, n - 1);
    }
private:
    vector<unordered_map<int, int>> process(int n, vector<vector<int>>& edges) {
        vector<unordered_map<int, int>> m(n);
        for (auto& e : edges) {
            if (!m[e[0]].count(e[1]) || m[e[0]][e[1]] > e[2]) m[e[0]][e[1]] = e[2];
            if (!m[e[1]].count(e[0]) || m[e[1]][e[0]] > 2 * e[2]) m[e[1]][e[0]] = 2 * e[2];
        }
        return m;
    }
    int dijkstra(vector<unordered_map<int, int>>& m, int s, int e) {
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        unordered_set<int> seen;
        for (auto& p : m[s]) pq.push({p.second, p.first});
        seen.insert(s);
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.second == e) return cur.first;
            seen.insert(cur.second);
            for (auto& p : m[cur.second]) {
                if (seen.count(p.first)) continue;
                pq.push({p.second + cur.first, p.first});
            }
        }
        return -1;
    }
};