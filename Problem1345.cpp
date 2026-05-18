#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::deque;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> map;
        unordered_set<int> seen;
        for (int i = 0; i < size(arr); i++) map[arr[i]].push_back(i);
        deque<int> queue;
        queue.push_back(0);
        seen.insert(0);
        int ans = 0;
        while(!queue.empty()) {
            for (int i = size(queue); i > 0; i--) {
                int cur = queue.front();
                queue.pop_front();
                if (cur == size(arr) - 1) return ans;
                if (cur + 1 < size(arr) && !seen.count(cur + 1)) {
                    queue.push_back(cur + 1);
                    seen.insert(cur + 1);
                }
                if (cur - 1 >= 0 && !seen.count(cur - 1)) {
                    queue.push_back(cur - 1);
                    seen.insert(cur - 1);
                }
                for (int j : map[arr[cur]]) {
                    if (j != cur && !seen.count(j)) {
                        queue.push_back(j);
                        seen.insert(j);
                    }
                }
                map.erase(arr[cur]);
            }
            ans++;
        }
        return -1;
    }
};
