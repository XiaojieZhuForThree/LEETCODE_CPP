#include <string>
#include <vector>
#include <algorithm>
using std::string;

class Solution {
public:
    string sortVowels(string s) {
        std::vector<char> v;
        for (char c : s) {
            if (yes(c)) v.push_back(c);
        }
        sort(begin(v), end(v));
        int i = 0;
        for (int j = 0; j < size(s); j++) {
            if (yes(s[j])) s[j] = v[i++];
        }
        return s;
    }
private:
    bool yes(char c) {
        char cl = tolower(c);
        return cl == 'a' || cl == 'e' || cl == 'i' || cl == 'o' || cl == 'u';
    }
};