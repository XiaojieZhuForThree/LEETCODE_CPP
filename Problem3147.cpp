#include <vector>
using std::vector;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        for (int i = 0; i < size(energy); i++) {
            if (i >= k) energy[i] = std::max(energy[i], energy[i] + energy[i - k]);
        }
        int ans = INT_MIN;
        for (int i = 1; i <= k; i++) ans = std::max(ans, energy[size(energy) - i]);
        return ans;
    }
};