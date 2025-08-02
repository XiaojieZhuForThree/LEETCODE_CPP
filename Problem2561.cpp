#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        std::unordered_map<int, int> freq;
        for (int i : basket1) freq[i]++;
        for (int i : basket2) freq[i]--;
        vector<int> extra;
        int s = 1e9;
        for (auto& p : freq) {
            if (p.second % 2) return -1;
            for (int i = 0; i < abs(p.second) / 2; i++) extra.push_back(p.first);
            s = std::min(s, p.first);
        }
        sort(extra.begin(), extra.end());
        long long ans = 0;
        for (int i = 0; i < extra.size() / 2; i++) ans += std::min(extra[i], 2 * s);
        return ans;
    }
};