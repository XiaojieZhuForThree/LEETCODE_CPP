#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        std::unordered_map<int, int> m;
        for (int i = 0; i < size(nums); i++) {
            m[nums[i]]++;
            if (i - k >= 0) m[nums[i - k]]--;
            if (i >= k - 1) ans.push_back(helper(m, x));
        }
        return ans;
    }
private:
    int helper(std::unordered_map<int, int>& m, int x) {
        auto comp = [&m](int i, int j) {
            if (m[i] == m[j]) return i < j;
            return m[i] < m[j];
        };
        std::priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto& p : m) pq.push(p.first);
        int ans = 0;
        for (int i = 0; i < x && !pq.empty(); i++) {
            int cur = pq.top();
            pq.pop();
            ans += m[cur] * cur;
        }
        return ans;
    }
};