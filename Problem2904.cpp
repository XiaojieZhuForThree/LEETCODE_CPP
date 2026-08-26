#include <string>
using std::string;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int cnt = 0, l = 0;
        for (int r = 0; r < size(s); r++) {
            if (s[r] == '1') cnt++;
            if (cnt >= k) {
                while (l < r) {
                    if (s[l] == '0') l++;
                    else if (cnt == k) break;
                    else {
                        cnt--;
                        l++;
                    }
                }
                string cand = s.substr(l, r - l + 1);
                if (yes(cand, ans)) ans = cand;
            }
        }
        return ans;
    }
private:
    bool yes(string& a, string& b) {
        if (b == "") return true;
        if (size(a) < size(b)) return true;
        if (size(a) > size(b)) return false;
        for (int i = 0; i < size(a); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }
};