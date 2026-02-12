#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0, n = size(s);
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> m;
            for (int j = i; j < n; j++) {
                m[s[j]]++;
                if (yes(m)) ans = std::max(ans, j - i + 1);
            }
        }
        return ans;
    }
private:
    bool yes(unordered_map<int, int>& m) {
        int cur = -1;
        for (auto& p : m) {
            if (cur == -1) cur = p.second;
            if (cur != p.second) return false;
        }
        return true;
    }
};