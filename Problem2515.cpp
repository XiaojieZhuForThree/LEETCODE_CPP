#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        unordered_set<int> s;
        for (int i = 0; i < size(words); i++) {
            if (words[i] != target) continue;
            s.insert(i);
        }
        int ans = -1;
        for (int i : s) {
            int val1 = abs(i - startIndex), val2 = size(words) - val1, val3 = std::min(val1, val2);
            if (ans == -1 || ans > val3) ans = val3;
        }
        return ans;
    }
};