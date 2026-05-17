#include <vector>
#include <unordered_set>
#include <deque>
using std::vector;
using std::unordered_set;
using std::deque;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        deque<int> q;
        q.push_back(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            if (arr[cur] == 0) return true;
            visited.insert(cur);
            int l = cur - arr[cur], r = cur + arr[cur];
            if (l >= 0 && !visited.count(l)) q.push_back(l);
            if (r < size(arr) && !visited.count(r)) q.push_back(r);
        }
        return false;
    }
};
