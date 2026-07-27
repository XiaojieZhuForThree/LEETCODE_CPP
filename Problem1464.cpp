#include <vector>
using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f = 0, s = 0;
        for (int i : nums) {
            if (i > f) {
                s = f;
                f = i;
            } else if (i > s) s = i;
        }
        return (f - 1) * (s - 1);
    }
};
