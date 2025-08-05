#include <vector>
using std::vector;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for (int i : fruits) {
            bool no = true;
            for (int j = 0; j < size(baskets); j++) {
                if (baskets[j] >= i) {
                    baskets[j] = 0;
                    no = false;
                    break;
                }
            }
            if (no) ans++;
        }
        return ans;
    }
};