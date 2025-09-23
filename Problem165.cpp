#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::vector<int> v1 = helper(version1), v2 = helper(version2);
        return comp(v1, v2);
    }
private:
    std::vector<int> helper(string s) {
        int l = 0;
        std::vector<int> ans;
        for (int r = 0; r <= size(s); r++) {
            if (r == size(s) || s[r] == '.') {
                ans.push_back(stoi(s.substr(l, r - l)));
                l = r + 1;
            }
        }
        return ans;
    }
    int comp(std::vector<int>& a, std::vector<int> b) {
        int i = 0, j = 0;
        while (i < size(a) || j < size(b)) {
            int x = 0, y = 0;
            if (i < size(a)) x = a[i++];
            if (j < size(b)) y = b[j++];
            if (x < y) return -1;
            else if (x > y) return 1;
        }
        return 0;
    }
};