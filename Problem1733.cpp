#include <vector>
#include <unordered_set>
using std::vector;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<std::unordered_set<int>> ls(size(languages));
        for (int i = 0; i < size(languages); i++) {
            for (int j : languages[i]) ls[i].insert(j);
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            std::unordered_set<int> checked;
            for (auto& f : friendships) {
                if (yes(f, ls)) continue;
                cur += add(f[0] - 1, i, ls, checked);
                cur += add(f[1] - 1, i, ls, checked);
            }
            ans = std::min(ans, cur);
        }
        return ans;
    }
private:
    bool yes(vector<int>& f, vector<std::unordered_set<int>>& ls) {
        for (int i : ls[f[0] - 1]) {
            if (ls[f[1] - 1].count(i)) return true;
        }
        return false;
    }
    int add(int j, int i, vector<std::unordered_set<int>>& ls, std::unordered_set<int>& checked) {
        if (checked.count(j)) return 0;
        checked.insert(j);
        if (ls[j].count(i)) return 0;
        return 1;
    }
};