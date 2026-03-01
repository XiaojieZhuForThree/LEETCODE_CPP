#include <string>
using std::string;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c : n) ans = std::max(ans, c - '0');
        return ans;
    }
};