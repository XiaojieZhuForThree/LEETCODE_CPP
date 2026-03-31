#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
    string word;
    string s1, s2;
    int n, m;
    vector<bool> fixed;
    bool breaksRule(int idx) {
        int sw = idx - m + 1;
        if (sw >= 0 && s1[sw] == 'F') {
            for (int j = 0; j < m; j++) {
                if (word[sw + j] != s2[j]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    bool solve(int idx) {
        if (idx == n + m - 1) return true;
        if (fixed[idx]) {
            if (breaksRule(idx)) return false;
            return solve(idx + 1);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            word[idx] = c;
            if (!breaksRule(idx)) {
                if (solve(idx + 1) == true) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    string generateString(string str1, string str2) {
        n = str1.length();
        m = str2.length();
        s1 = str1; 
        s2 = str2;
        int len = n + m - 1;
        word = string(len, 'a');
        fixed = vector<bool>(len, false);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (fixed[i + j] && word[i + j] != str2[j]) return "";
                    word[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool all_fixed = true, match = true;
                for (int j = 0; j < m; j++) {
                    if (!fixed[i + j]) all_fixed = false;
                    if (word[i + j] != s2[j]) match = false;
                }
                if (all_fixed && match) return "";
            }
        }
        if (solve(0) == true) return word;
        return "";
    }
};