#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int p = 0, ans = 0;
        for (auto& s : bank) {
            int cur = 0;
            for (char c : s) cur += c == '1';
            if (cur == 0) continue;
            ans += p * cur;
            p = cur;
        }
        return ans;
    }
};