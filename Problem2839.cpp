#include <string>
using std::string;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return yes(s1, s2, 0, 2) && yes(s1, s2, 1, 3);
    }
private:
    bool yes(string& s1, string& s2, int i, int j){
        return (s1[i] == s2[i] && s1[j] == s2[j]) ||
                (s1[j] == s2[i] && s1[i] == s2[j]);
    }
};