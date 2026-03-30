#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> s1e, s2e, s1o, s2o;
        for (int i = 0; i < size(s1); i++) {
            if (i % 2 == 0) {
                s1e[s1[i]]++;
                s2e[s2[i]]++;
            } else {
                s1o[s1[i]]++;
                s2o[s2[i]]++;
            }
        }
        return yes(s1e, s2e) && yes(s1o, s2o);
    }
private:
    bool yes(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (char c  = 'a'; c <= 'z'; c++) {
            if (m1[c] != m2[c]) return false;
        }
        return true;
    }
};