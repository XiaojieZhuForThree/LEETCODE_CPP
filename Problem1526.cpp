#include <vector>
using std::vector;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < size(target); i++) {
            if (target[i] > target[i - 1]) ans += target[i] - target[i - 1];
        }
        return ans;
    }
};