#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0, ans = 0;
        for (int r = 0; r < size(s); r++) {
            m[s[r]]++;
            while (m[s[r]] > 2) m[s[l++]]--;
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};
