#include <string>
#include <unordered_set>
using std::string;

class Solution {
public:
    bool doesAliceWin(string s) {
        std::unordered_set<char> v {'a', 'e', 'i', 'o', 'u'};
        for (char c : s) {
            if (v.count(c)) return true;
        }
        return false;
    }
};