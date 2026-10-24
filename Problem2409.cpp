#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::min;
using std::max;

class Solution {
public:
    vector<int> ds = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> ms;
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        ms.resize(12, 1);
        for (int i = 1; i < 12; i++) ms[i] = ms[i - 1] + ds[i - 1];
        int aa = helper(arriveAlice), la = helper(leaveAlice), ab = helper(arriveBob), lb = helper(leaveBob);
        int ans = min(la, lb) - max(aa, ab);
        if (ans < 0) return 0;
        return ans + 1;
    }

private:
    int helper(string& s) {
        int pos = s.find('-');
        int m = stoi(s.substr(0, pos)), d = stoi(s.substr(pos + 1, size(s) - pos));
        return ms[m - 1] + d;
    }
};
