#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = size(strs), n = size(strs[0]), ans = 0;
        vector<string> prev(m, "");
        for (int j = 0; j < n; j++) {
            int val = check(prev, strs, j);
            if (val == 0) break;
            else if (val == 2) ans++;
            else {
                for (int i = 0; i < m; i++) prev[i] += strs[i][j];
            }
        }
        return ans;
    }
private:
    int check(vector<string>& prev, vector<string>& strs, int j) {
        int ans = 0;
        for (int i = 1; i < size(strs); i++) {
            if (prev[i] + strs[i][j] < prev[i - 1] + strs[i - 1][j]) {
                ans = 2;
                break;
            } else if (prev[i] + strs[i][j] == prev[i - 1] + strs[i - 1][j]) ans = 1;
        }
        return ans;
    }
};