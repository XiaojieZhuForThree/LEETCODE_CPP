#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0);
        int ans = size(nums);
        for (int num : nums) {
            if (num >= 0 || num % value == 0) v[num % value]++;
            else v[value - (abs(num) % value)]++;
        }

        for (int i = 0; i < value; i++) ans = std::min(ans, v[i] * value + i);
        return ans;
    }
};