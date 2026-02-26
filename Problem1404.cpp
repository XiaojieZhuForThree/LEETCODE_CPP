#include <string>
using std::string;

class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            ans++;
            if (s[size(s) - 1] == '0') s = s.substr(0, size(s) - 1);
            else s = add(s);
        }
        return ans;
    }
private:
    string add(string& s) {
        int car = 1, i = size(s) - 1;
        while (car) {
            car = 0;
            if (i < 0) s = "1" + s;
            else if (s[i] == '0') s[i] = '1';
            else {
                s[i] = '0';
                car = 1;
            }
            i--;
        }
        return s;
    }
};