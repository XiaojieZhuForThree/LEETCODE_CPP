#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int numberOfWays(string corridor) {
        if (!valid(corridor)) return 0;
        std::vector<int> ve, vo;
        int cnt = 0;
        long long ans = 1;
        for (int i = 0; i < size(corridor); i++) {
            if (corridor[i] == 'P') continue;
            cnt++;
            if (cnt == 1) vo.push_back(i);
            else if (cnt == 2) {
                ve.push_back(i);
                cnt = 0;
            }
        }
        for (int i = 0; i < size(ve); i++) {
            if (i + 1 >= size(vo)) break;
            int o = vo[i + 1], e = ve[i];
            ans *= (o - e);
            ans %= 1000000007;
        }
        return ans;
    }
private:
    bool valid(string& s) {
        int cnt = 0;
        for (char c : s) {
            if (c == 'S') cnt++;
        }
        return cnt >= 2 && cnt % 2 == 0;
    }
};