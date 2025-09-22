#include <vector>
using std::vector;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int a[101], m = 0, ans = 0;
        for (int i : nums) {
            a[i]++;
            m = std::max(m, a[i]);
        }
        for (int i : a) {
            if (i == m) ans += i;
        }
        return ans;
    }
};