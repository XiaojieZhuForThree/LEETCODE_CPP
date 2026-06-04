#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) ans += helper(i);
        return ans;
    }

private:
    int helper(int i) {
        int ans = 0;
        string s = to_string(i);
        for (int j = 1; j + 1 < size(s); j++) {
            if (s[j] < s[j + 1] && s[j] < s[j - 1]) ans++;
            if (s[j] > s[j + 1] && s[j] > s[j - 1]) ans++;
        }
        return ans;
    }
};