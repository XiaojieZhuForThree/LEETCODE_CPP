#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& s : operations) {
            if (s == "++X" || s == "X++") ans++;
            else ans--;
        }
        return ans;
    }
};