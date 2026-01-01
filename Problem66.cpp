#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int car = 1;
        for (int i = size(digits) - 1; i >= 0; i--) {
            int cur = car + digits[i];
            ans.push_back(cur % 10);
            car = cur / 10;
        }
        if (car) ans.push_back(car);
        std::reverse(begin(ans), end(ans));
        return ans;
    }
};