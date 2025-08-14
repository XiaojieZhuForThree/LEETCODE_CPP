#include <string>
using std::string;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < size(num); i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) ans = std::max(ans, num.substr(i, 3));
        }
        return ans;
    }
};