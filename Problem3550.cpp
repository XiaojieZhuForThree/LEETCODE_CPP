#include <vector>
using std::vector;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < size(nums); i++) {
            if (yes(nums[i], i)) return i;
        }
        return -1;
    }
private:
    bool yes(int a, int b) {
        int c = 0;
        while (a) {
            c += a % 10;
            a /= 10;
        }
        return c == b;
    }
};
