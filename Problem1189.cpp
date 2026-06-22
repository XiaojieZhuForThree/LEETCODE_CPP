#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (char c : text) m[c]++;
        int ans = 10000;
        for (char c : "balon") {
            if (!c) continue;
            if (c == 'l' || c == 'o') ans = std::min(ans, m[c] / 2);
            else ans = std::min(ans, m[c]);
        }
        return ans;
    }
};
