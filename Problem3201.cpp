#include <vector>
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oo = 0, oe = 0,  eo = 0, ee = 0;
        for (int i : nums) {
            if (i % 2) {
                oo = 1 + eo;
                oe++;
            } else {
                eo = 1 + oo;
                ee++;
            }
        }
        return std::max(std::max(oo, oe), std::max(eo, ee));
    }
};