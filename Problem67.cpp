#include <string>
#include <algorithm>
using std::string;
using std::to_string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        int l = 0, r = 0, car = 0;
        while (l < size(a) || r < size(b)) {
            int cur = car;
            if (l < size(a)) cur += a[l++] - '0';
            if (r < size(b)) cur += b[r++] - '0';
            car = cur / 2;
            ans += to_string(cur % 2);
        }
        if (car) ans += to_string(car);
        reverse(begin(ans), end(ans));
        return ans;
    }
};