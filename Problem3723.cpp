#include <string>
using std::string;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        if (9 * num < sum) return ans;
        ans.reserve(num);
        for (int i = 0; i < num; i++) {
            int cand = std::min(sum, 9);
            ans += '0' + cand;
            sum -= cand;
        }
        return ans;
    }
};
