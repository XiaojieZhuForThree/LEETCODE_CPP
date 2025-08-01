#include <string>
using std::string;

class Solution {
public:
    bool isValid(string word) {
        if (size(word) < 3) return false;
        bool vc = false, cc = false;
        for (char c : word) {
            if (!isalnum(c)) return false;
            if (isdigit(c)) continue;
            if (isVowel(c)) vc = true;
            else cc = true;
        }
        return vc && cc;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') return true;
        return false;
    }
};