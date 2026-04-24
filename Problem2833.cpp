#include <string>
using std::string;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0, cnt = 0;
        for (char c : moves) {
            if (c == 'L') ans--;
            else if (c == 'R') ans++;
            else cnt++;
        }
        return abs(ans) + cnt;
    }
};