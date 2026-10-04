#include <string>
#include <deque>
using std::string;
using std::deque;

class Solution {
public:
    bool checkValidString(string s) {
        deque<int> l, w;
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '(') l.push_back(i);
            else if (s[i] == '*') w.push_back(i);
            else if (!l.empty()) l.pop_back();
            else if (!w.empty()) w.pop_back();
            else return false;
        }
        for (int i : l) {
            while (!w.empty() && w.front() < i) w.pop_front();
            if (w.empty()) return false;
            w.pop_front();
        }
        return true;
    }
};
