#include <vector>
#include <deque>
#include <unordered_map>
using std::vector;
using std::deque;
using std::unordered_map;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, deque<int>> m;
        for (int i = 0; i < size(nums); i++) {
            m[nums[i]].push_back(i);
            auto& q = m[nums[i]];
            if (size(q) < 3) continue;
            while (size(q) > 3) q.pop_front();
            int cand = abs(q[0] - q[1]) + abs(q[1] - q[2]) + abs(q[2] - q[0]);
            if (ans == -1 || ans > cand) ans = cand;
        }
        return ans;
    }
};