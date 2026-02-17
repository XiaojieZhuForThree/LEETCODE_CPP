#include <vector>
#include <unordered_set>
#include <string>
using std::vector;
using std::string;
using std::unordered_set;
using std::to_string;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        unordered_set<int> hours = {1, 2, 4, 8}, mins = {1, 2, 4, 8, 16, 32};
        for (int i = 0; i <= turnedOn; i++) {
            int j = turnedOn - i;
            unordered_set<int> hour = helper(i, hours, 11), min = helper(j, mins, 59);
            for (int i : hour) {
                for (int j : min) {
                    string cur = to_string(i) + ":";
                    if (j < 10) cur += "0";
                    cur += to_string(j);
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
private:
    unordered_set<int> helper(int i, unordered_set<int>& s, int limit) {
        if (i == 0) return {0};
        unordered_set<int> ans;
        for (int cur : s) {
            unordered_set<int> n;
            for (int j : s) {
                if (j == cur) continue;
                n.insert(j);
            }
            for (int nxt : helper(i - 1, n, limit)) {
                if (cur + nxt > limit) continue;
                ans.insert(cur + nxt);
            }
        }
        return ans;
    }
};