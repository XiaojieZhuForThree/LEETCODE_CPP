#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using std::string;
using std::unordered_map;
using std::vector;
using std::priority_queue;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (char c : word) m[c]++;
        int ans = 0, cur = 0;
        auto comp = [&m](char a, char b) {
            return m[a] < m[b];
        };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        for (auto& p : m) pq.push(p.first);
        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();
            ans += (1 + (cur / 8)) * m[c];
            cur++;
        }
        return ans;
    }
};
