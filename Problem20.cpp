#include <string>
#include <deque>
using std::string;
using std::deque;

class Solution {
public:
    bool isValid(string s) {
        deque<char> l;
        for (char c : s) {
            if (c == ')') {
                if (l.empty() || l.back() != '(') return false;
                else l.pop_back();
            } else if (c == ']') {
                if (l.empty() || l.back() != '[') return false;
                else l.pop_back();
            } else if (c == '}') {
                if (l.empty() || l.back() != '{') return false;
                else l.pop_back();
            } else l.push_back(c);
        }
        return l.empty();
    }
};
