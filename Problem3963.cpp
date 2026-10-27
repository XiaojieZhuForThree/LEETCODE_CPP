#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s;
        for (int i = 0; i < n; i++) s += '.';
        ans.push_back(s);
        for (int i = 1; i < m; i++) {
            s.clear();
            for (int j = 0; j < n - 1; j++) s += '#';
            s += '.';
            ans.push_back(s);
        }
        return ans;
    }
};
