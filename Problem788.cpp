#include <vector>
#include <string>
using std::string;
using std::to_string;
using std::vector;

class Solution
{
public:
    vector<int> v = {0, 1, 8, 2, 5, 6, 9};
    int dp[6][2][2];
    int f(string &num, int pos, int tight, int diff)
    {
        if (pos >= (num.length()))
        {
            return (diff >= 1);
        }
        if (dp[pos][tight][diff] != -1)
            return dp[pos][tight][diff];

        int ub = (tight) ? num[pos] - '0' : 9;
        int res = 0;
        for (auto x : v)
        {
            if (x > ub)
                continue;
            if (x == 0 || x == 1 || x == 8)
                res += f(num, pos + 1, tight & (x == ub), diff);
            else
                res += f(num, pos + 1, tight & (x == ub), 1);
        }
        return dp[pos][tight][diff] = res;
    }
    int rotatedDigits(int n)
    {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return f(num, 0, 1, 0);
    }
};