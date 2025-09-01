#include <vector>
#include <queue>
using std::vector;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [](vector<int>& a, vector<int>& b) {
            return (double)(a[0] + 1) / (a[1] + 1) - (double)(a[0]) / a[1] < (double)(b[0] + 1) / (b[1] + 1) - (double)(b[0]) / b[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto& c : classes) pq.push(c);
        for (int i = 0; i < extraStudents; i++) {
            auto cur = pq.top();
            pq.pop();
            cur[0]++;
            cur[1]++;
            pq.push(cur);
        }
        double tot = 0.0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            tot += double(cur[0]) / cur[1];
        }
        return tot / size(classes);
    }
};