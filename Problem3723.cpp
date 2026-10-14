#include <string>
using std::string;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while (sum) {
            if (num == 0) return "";
            int cand = std::min(sum, 9);
            ans += (cand + '0');
            sum -= cand;
            num--;
        }
        for (int i = 0; i < num; i++) ans += '0';
        return ans;
    }
};
