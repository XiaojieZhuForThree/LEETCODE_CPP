#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::greater;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> res;
        for (int j = 0; j < size(s); ++j) {
            if (s[j] == '1') count++;
            else count--;
            if (count == 0) {
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(begin(res), end(res), greater<string>());
        string res2 = "";
        for (int i = 0; i < size(res); ++i) res2 += res[i];
        return res2;
    }
};