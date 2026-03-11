#include <string>
#include <algorithm>
using std::string;
using std::to_string;
using std::reverse;

class Solution {
public:
    int bitwiseComplement(int n) {
        string ans = "";
        if (n == 0) ans = "1";
        while (n) {
            ans += to_string(1 - (n % 2));
            n >>= 1;
        }
        reverse(begin(ans), end(ans));
        return stoi(ans, nullptr, 2);
    }
};