#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int i = size(strs), j = size(strs[0]), ans = 0;
        for (int k = 0; k < j; k++) {
            bool valid = true;
            for (int t = 1; t < i; t++) {
                if (strs[t][k] >= strs[t - 1][k]) continue;
                valid = false;
                break;
            }
            if (!valid) ans++;
        }
        return ans;
    }
};