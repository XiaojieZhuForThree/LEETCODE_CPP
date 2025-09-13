#include <string>
#include <unordered_set>
#include <unordered_map>
using std::string;

class Solution {
public:
    int maxFreqSum(string s) {
        std::unordered_set<char> v {'a', 'e', 'i', 'o', 'u'};
        std::unordered_map<char, int> m;
        for (char c : s) m[c]++;
        int cv = 0, cc = 0;
        for (auto& p : m) {
            if (v.count(p.first)) cv = std::max(cv, p.second);
            else cc = std::max(cc, p.second);
        }
        return cv + cc;
    }
};