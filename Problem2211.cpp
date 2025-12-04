#include <string>
#include <deque>
using std::string;

class Solution {
public:
    int countCollisions(string directions) {
        std::deque<char> stk;
        int ans = 0;
        for (char c : directions) {
            if (c == 'S') {
                while (!stk.empty() && stk.back() == 'R') {
                    ans++;
                    stk.pop_back();
                }
                stk.push_back(c);
            } else if (c == 'R') stk.push_back(c);
            else if (stk.empty()) continue;
            else if (stk.back() == 'S') ans++;
            else {
                ans++;
                while (!stk.empty() && stk.back() == 'R') {
                    ans++;
                    stk.pop_back();
                }
                stk.push_back('S');
            }
        }
        return ans;
    }
};