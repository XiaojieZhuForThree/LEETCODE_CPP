#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::max;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_map<int, unordered_set<int>> m;
        for (auto& o : obstacles) m[o[0]].insert(o[1]);
        int ptr = 0, x = 0, y = 0, ans = 0;
        for (int i : commands) {
            if (i == -2) ptr = (ptr - 1 + 4) % 4;
            else if (i == -1) ptr = (ptr + 1 + 4) % 4;
            else {
                auto& dir = dirs[ptr];
                for (int j = 0; j < i && !m[x + dir[0]].count(y + dir[1]); j++) {
                    x += dir[0];
                    y += dir[1];
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};